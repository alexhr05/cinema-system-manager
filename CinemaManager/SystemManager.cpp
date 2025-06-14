#include "SystemManager.h"
//#include <iostream>
#include <fstream>
//#include "MyVector.hpp"
#include "SeatTypes.h"
//#include "User.h"
//#include "Admin.h"
//#include "MoviesType.h"
//#include "ActionMovie.h"
//#include "DocumantaryMovie.h"
//#include "DramaMovie.h"


using namespace std;



SystemManager::SystemManager(): users(MyVector<User*>()), movies(MyVector<Movie*>()), halls(MyVector<Hall*>()),  allTickets(MyVector<Ticket>()), sessions(MyVector<Session*>()){
}

SystemManager::~SystemManager() {
    for (size_t i = 0; i < users.getSize(); i++) {
        delete users[i];
    }

    for (size_t i = 0; i < movies.getSize(); i++) {
        delete movies[i];
    }

    for (size_t i = 0; i < halls.getSize(); i++) {
        delete halls[i];
    }
    for (size_t i = 0; i < sessions.getSize(); i++) {
        delete sessions[i];
    }
}

void SystemManager::loadHallsFromFiles()
{
    
    std::ifstream inFile("halls.txt");
    if (!inFile.is_open()) return;
    int id, rows, cols;
    while (inFile >> id >> rows >> cols) {
        cout << endl;
        Hall* h = new Hall(rows, cols);
        cout << "";
        h->setId(id);
        halls.add(h);
    }
    
    inFile.close();
}

void SystemManager::saveHallsToFiles()
{
    ofstream outFile("halls.txt", ios::app);
    if (!outFile.is_open()) return;

    for (size_t i = 0; i < halls.getSize(); i++) {
        Hall* h = halls[i];
        outFile << h->getId() << "\n"
            << h->getRows() << '\n'
            << h->getCols() << '\n';
        
    }
    outFile.close();
}


tm SystemManager::createTimeStruct(int year, int month, int day, int hour)
{
    tm time;
    time.tm_year = year;
    time.tm_mon = month;
    time.tm_wday = day;
    time.tm_hour = hour;

    return time;
}

void SystemManager::loadTicketsFromFiles() {
    ifstream in("tickets.txt");
    if (!in.is_open()) {
        std::cerr << "Could not open tickets file"<<endl;
        return;
    }
    int id,row,col, sessionId;


    while (in>>id>>row>>col>> sessionId) {
            Session* session = findSessionById(sessionId);
            Ticket tick(session,row,col);
            allTickets.add(tick);
    }
    

    in.close();
}

void SystemManager::saveTicketsToFiles() {
    ofstream outFile("tickets.txt", ios::app);
    if (!outFile.is_open()) return;
  
    for (size_t i = 0; i < allTickets.getSize(); i++) {
        Ticket ticket = allTickets[i];

        outFile << ticket.getId() << "\n"
            << ticket.getRow() << "\n"
            << ticket.getCol() << "\n"
            << ticket.getSession()->getId() << '\n';
    }

    outFile.close();
}

void SystemManager::loadUsersFromFiles()
{
    std::ifstream in("users.txt");
    if (!in.is_open()) {
        std::cerr << "Could not open user file. Creating default admin.\n";
        addDefaultAdmin();
        return;
    }
    
    addDefaultAdmin();
    
    int id;
    MyString name, password;
    double balance;
    bool adminExists = false;
    int ticketsSize, ticketId, watchedMoviesSize, watchedMovieId;
    while (in >> id) {

        in.ignore();
        getline(in, name, '\n');

        getline(in, password, '\n');
        in >> balance>> ticketsSize;
        
        User* user = new User(name, password, balance);
        user->setId(id);
        for (size_t i = 0; i < ticketsSize; i++) {
            in >> ticketId;
            Ticket ticket = findTicketById(ticketId) ;
            allTickets.add(ticket);
            user->addTicket(ticket);   
        }

        in >> watchedMoviesSize;
        
        for (size_t i = 0; i < watchedMoviesSize; i++) {
            in >> watchedMovieId;
            
            Movie* movie = findMovieById(watchedMovieId);
            user->addWatchedMovies(movie);
            
        }
        if (watchedMoviesSize == 0) {
            in >> watchedMovieId;
        }
        users.add(user);
        
        
    }
    
    in.close();
}

Ticket SystemManager::findTicketById(int id) {
    for (int i = 0; i < allTickets.getSize(); i++) {
        
        if (allTickets[i].getId() == id) {
            return allTickets[i]; 
        }
        
    }

    cout << "Ticket not Found" << endl;
    Ticket tick;
    return tick;
}

Movie* SystemManager::findMovieById(int id) {
    
    for (int i = 0; i < movies.getSize(); i++) {
        if (movies[i]->getId() == id) {
            return movies[i];
        }
        
    }
    
    cout << "Movie not Found"<<endl;
    return nullptr;
}

Session* SystemManager::findSessionById(int id)
{
    for (int i = 0; i < sessions.getSize(); i++) {
        if (sessions[i]->getId() == id) {
            return sessions[i];
        }

    }

    cout << "Session not Found" << endl;
    
    return nullptr;
}

User* SystemManager::findUserById(int id)
{
    for (int i = 0; i < users.getSize(); i++) {
        if (users[i]->getId() == id) {
            return users[i];
        }

    }

    cout << "User not Found" << endl;

    return nullptr;
}

void SystemManager::addDefaultAdmin() {
    MyString defaultName = "admin";
    MyString defaultPassword = "admin123";
    double balance = 10000;
    User* admin = new Admin(defaultName, defaultPassword, balance);
    admin->setId(1);
    users.add(admin);

    cout << "Default admin created: admin / admin123\n";

}



void SystemManager::saveUsersToFiles()
{
    ofstream outFile("users.txt", ios::out);
    if (!outFile.is_open()) return;
    for (size_t i = 0; i < users.getSize(); i++) {
        
        User* user = users[i];
        if (user->getId() != 1 ) {
            outFile << user->getId() << "\n"
                << user->getName().c_str() << '\n'
                << user->getPassword().c_str() << '\n'
                << user->getBalance() << '\n';
            MyVector<Ticket> tickets;
            if (user->getTickets().getSize() > 0) {
                
                tickets = user->getTickets();
                outFile << tickets.getSize() << "\n";
                for (size_t j = 0; j < tickets.getSize(); j++) {
                    outFile << tickets[j].getId() << "\n";
                }
            }
            else if (user->getTickets().getSize() == 0) {
                outFile << user->getTickets().getSize() << "\n"
                    << 0 << "\n";
            }
            if (user->getWatchedMovies().getSize() > 0) {
                MyVector<Movie*> watchedMovies;
                watchedMovies = user->getWatchedMovies();
                outFile << watchedMovies.getSize() << "\n";
                for (size_t j = 0; j < watchedMovies.getSize(); j++) {
                    outFile << watchedMovies[j]->getId() << "\n";
                }
            }
            else if (user->getWatchedMovies().getSize() == 0) {
                outFile << user->getWatchedMovies().getSize() << "\n"
                    << 0 << "\n";
            }
        }
    }
    outFile.close();
}



void SystemManager::loadMoviesFromFile()
{
    std::ifstream in("movies.txt");
    if (!in.is_open()) {
        std::cerr << "Could not open user file. Creating default admin.\n";
        addDefaultAdmin();
        return;
    }


    int id, productionYear, startHour, endHour, rate, hallId, type , actionIntensity,
        year, month, day, hour, timeSesionSize;
    
    double duration;
    MyString title, genre;
    
    
    bool isBasedOnTrueEvents, hasComedyElements;
    

    while (in >> id >> type) {
        in.ignore();
        
        getline(in, title, '\n');
        
        in >> rate >> duration >> productionYear;
        in.ignore();
        getline(in, genre, '\n');
        
        
        Movie* movie = nullptr;
        MoviesType movieType = static_cast<MoviesType>(type);

        switch (movieType) {
        case MoviesType::ActionMovie:
            in >> actionIntensity;
            movie = new ActionMovie(title, rate, duration, productionYear, genre, movieType, actionIntensity);
            
            break;
        case MoviesType::DocumentaryMovie:
            in >> isBasedOnTrueEvents;
            movie = new DocumentaryMovie(title, rate, duration, productionYear, genre, movieType, isBasedOnTrueEvents);
            break;
        case MoviesType::DramaMovie:
            in >> hasComedyElements;
            movie = new DramaMovie(title, rate, duration, productionYear, genre, movieType, hasComedyElements);
            break;
        default:
            cout << "Unknown movie type: " << type << endl;
        }
        movie->setId(id);
        //cout << endl << endl;
        ////movie->print();
        //cout << endl << endl;
        movies.add(movie);
        
        
    }
    in.close();
}

void SystemManager::saveMoviesToFile()
{

    ofstream outFile("movies.txt", ios::app);
  

    for (size_t i = 0; i < movies.getSize(); i++)
    {
        outFile << movies[i]->getId() << "\n"
            << static_cast<int>(movies[i]->getMovieType()) << "\n"
            << movies[i]->getTitle().c_str() << "\n"
            << movies[i]->getRate() << "\n"
            << movies[i]->getDuration() << "\n"
            << movies[i]->getProductionYear() << "\n"
            << movies[i]->getGenre().c_str() << "\n";
           
        
        switch (movies[i]->getMovieType()) {
        case MoviesType::ActionMovie: {
            ActionMovie* action = dynamic_cast<ActionMovie*>(movies[i]);
            outFile << action->getActionIntensity() << "\n";
            break;
        }   
        case MoviesType::DocumentaryMovie: {
            DocumentaryMovie* documentary = dynamic_cast<DocumentaryMovie*>(movies[i]);
            outFile << documentary->getIsBasedOnTrueEvents() << "\n";
            break;
        }   
        case MoviesType::DramaMovie: {
            DramaMovie* drama = dynamic_cast<DramaMovie*>(movies[i]);
            outFile << drama->getHasComedyElements() << "\n";
            break;
        }
        default:
            cout << "Unknown movie type: " << static_cast<int>(movies[i]->getMovieType())<< endl;
        }
            
    }


    outFile.close();
}

void SystemManager::saveSessionToFile() {
    ofstream outFile("session.txt");
    MyString name = "Star wars";
    MyString gen = "fic";
    Movie* movie = new ActionMovie(name, 3, 2.5, 2000, gen, MoviesType::ActionMovie, 15);
    Hall* hall = new Hall(5,5);
    tm time = {};
    time.tm_year = 200;
    time.tm_mon = 2;
    time.tm_wday = 12;
    time.tm_hour = 2;
    Session* session = new Session(movie, hall, time);
    sessions.add(session);

    cout << "session:size::" << sessions.getSize()<<"id:"<<session->getId()<<endl;
    for (int i = 0; i < sessions.getSize(); i++)
    {
        
        outFile << sessions[i]->getId() << "\n"
            << sessions[i]->getMovie()->getId() << "\n"
            << sessions[i]->getHall()->getId() << "\n"
            << sessions[i]->getStartTime().tm_year << "\n"
            << sessions[i]->getStartTime().tm_mon << "\n"
            << sessions[i]->getStartTime().tm_mday << "\n"
            << sessions[i]->getStartTime().tm_hour << "\n";

        for (int j = 0; j < sessions[i]->getHall()->getRows(); j++) {
            for (int q = 0; q < sessions[i]->getHall()->getCols(); q++) {
                outFile << sessions[i]->getSeat(j,q);
            }
            outFile << "\n";
        }

    }

    outFile.close();
}


void SystemManager::loadSessionFromFile() {
    
    ifstream inFile("session.txt");
    if (!inFile.is_open()) {
        cerr << "Could not open session.txt\n";
        return;
    }

    int sessionId, movieId, hallId, year, month, day, hour;

    while (inFile >> sessionId >> movieId >> hallId >> year >> month >> day >> hour) {
        
        Movie* movie = findMovieById(movieId);
        Hall* hall = findHallById(hallId);

        if (!movie || !hall) {
            cerr << "Invalid movie or hall ID in session file.\n";
            continue;
        }

        tm timeStruct = {};
        timeStruct.tm_year = year;
        timeStruct.tm_mon = month;
        timeStruct.tm_mday = day;
        timeStruct.tm_hour = hour;

        Session* session = new Session(movie, hall, timeStruct);
        session->setId(sessionId);

        for (int i = 0; i < hall->getRows(); i++) {
            inFile.ignore();
            for (int j = 0; j < hall->getCols(); j++) {
                SeatTypes type = static_cast<SeatTypes>(inFile.get());
                if (type == SeatTypes::Reserved) {
                    session->reserveSeat(i, j);
                }
            }
        }
        sessions.add(session);
    }

    inFile.close();
}



User* SystemManager::login(MyString name, MyString password) {
    for (size_t i = 0; i < users.getSize(); i++) {
        if (users[i]->getName().equals(name) && users[i]->getPassword().equals(password)) {
            return users[i];
        }
    }
    return nullptr;
}

void SystemManager::addMovie(Movie* movie)
{
   
    movies.add(movie);
}

void SystemManager::addHall(Hall* hall)
{

    halls.add(hall);
}

void SystemManager::addTicket(Ticket ticket)
{
    allTickets.add(ticket);
}

MyVector<User*> SystemManager::getUsers() const
{
    return users;
}

MyVector<Movie*> SystemManager::getMovies() const
{
    return movies;
}

MyVector<Hall*> SystemManager::getHalls() const
{
    return halls;
}

MyVector<Ticket> SystemManager::getAllTickets() const
{
    return allTickets;
}

MyVector<Session*> SystemManager::getSessions() const
{
    return sessions;
}

bool SystemManager::registerUser(MyString name, MyString password, double balance) {
    for (size_t i = 0; i < users.getSize(); i++)
    {
        if(users[i]->getName().equals(name) && users[i]->getPassword().equals(password)) {
            return false;
        }
    }

    User* user = new User(name, password, balance);
    users.add(user);
    return true;
}

Hall* SystemManager::findHallById(int id) {
    for (size_t i = 0; i < halls.getSize(); i++) {
        if (halls[i]->getId() == id) {
            return halls[i];
        }
    }
    return nullptr;
}

void SystemManager::removeMovieSystem(int movieId) {
    Movie* targetMovie = findMovieById(movieId);
    if (targetMovie == nullptr) {
        cout << "Movie is missing";
        return;
    }
    bool isMovieInSession = true;
    for (size_t i = 0; i < users.getSize(); i++)
    {
        MyVector<Ticket> tickets = users[i]->getTickets();
        for (size_t j = 0; j < tickets.getSize(); j++)
        {
            Session* session = tickets[j].getSession();
            MoviesType movieTypeFromSession = session->getMovie()->getMovieType();
            Movie* movieFromSession = session->getMovie();
            if (targetMovie->getId() == movieFromSession->getId()) {
                int priceTicket = targetMovie->getTicketPrice();
                users[i]->setBalance(users[i]->getBalance() + priceTicket);
                tickets.remove(tickets[j]);
                sessions.remove(session);
                allTickets.remove(tickets[j]);
                users[i]->setTickets(tickets);
                isMovieInSession = false;
            }
        }
        
        MyVector<Movie*> watchedMovies = users[i]->getWatchedMovies();
        for (size_t q = 0; q < watchedMovies.getSize(); q++)
        {
            if (watchedMovies[q]->getId() == targetMovie->getId() && !isMovieInSession) {
                watchedMovies.remove(watchedMovies[q]);
                users[i]->setWatchedMovies(watchedMovies);
            }
        }
        
    }
    

    movies.remove(targetMovie);

}

void SystemManager::removeHallSystem(int hallId) {
    Hall* hall = findHallById(hallId);
    if (hall == nullptr)
        return;
    for (size_t i = 0; i < users.getSize(); i++)
    {
        MyVector<Ticket> tickets = users[i]->getTickets();
        for (size_t j = 0; j < tickets.getSize(); j++)
        {
            Session* session = tickets[j].getSession();
            Movie* movie = session->getMovie();
            Hall* hallFromSession = session->getHall();
            
            if (hall->getId() == hallFromSession->getId()) {
                int priceTicket = movie->getTicketPrice();
                users[i]->setBalance(users[i]->getBalance() + priceTicket);
                
                tickets.remove(tickets[j]);
                sessions.remove(session);
                allTickets.remove(tickets[j]);
                users[i]->setTickets(tickets);
            }
        }
        
    }
    halls.remove(hall);
    
}

void SystemManager::removeUserSystem(int userId)
{
    User* user = findUserById(userId);
    if (user == nullptr) {
        return;
    }

    for (size_t i = 0; i < users.getSize(); i++)
    {
        if (users[i]->getId() == user->getId()) {
            users.remove(user);
        }
    }
}

void SystemManager::printWatchedMovies(int userId)
{
    User* user = findUserById(userId);
    for (size_t j = 0; j < user->getWatchedMovies().getSize(); j++) {
        MyVector<Movie*> watchedMovie = user->getWatchedMovies();
        watchedMovie[j]->print();
    }
}

void SystemManager::printAllMoviesFromSessions() {
    cout << "Movies to watch:" << endl;
    for (size_t i = 0; i < sessions.getSize(); i++)
    {
        cout << "Name: " << sessions[i]->getMovie()->getTitle().c_str() << "; start time: " << sessions[i]->getStartTime().tm_hour<<endl;
    }
}

void SystemManager::printAllSessions()
{
    cout << "Info about all Sessions to buy ticket:" << endl<<endl;

    for (size_t i = 0; i < sessions.getSize(); i++)
    {
        cout << "Session id: " << sessions[i]->getId() << "\n"
            << "Movie: " << sessions[i]->getMovie()->getTitle().c_str() << "\n"
            << "Hall: " << sessions[i]->getHall()->getId()<<"\n"
            << "Start time: "<< sessions[i]->getStartTime().tm_hour << " "<< sessions[i]->getStartTime().tm_year
            <<"/"<< sessions[i]->getStartTime().tm_mon
            <<"/"<< sessions[i]->getStartTime().tm_wday<<"\n";
        sessions[i]->displaySeats();
        cout << endl;

    }
}

void SystemManager::printAllUsers()
{
    cout << "All users:" << endl<<endl;

    for (size_t i = 0; i < users.getSize(); i++)
    {
        cout << "User id: " << users[i]->getId() << "\n"
            << "Name: " << users[i]->getName().c_str() << "\n"
            << "Balance: " << users[i]->getBalance()<<"\n";
        cout << endl;

    }
}

void SystemManager::updateSystemMovieTitle(int movieId, MyString title)
{
    Movie* movie = findMovieById(movieId);
    movies.remove(movie);
    movie->setTitle(title);
    movies.add(movie);
}

void SystemManager::printAllUsersWatchedMovies(int userId) {
    printWatchedMovies(userId);   
}

void SystemManager::printAllUsersTickets(int userId) {
    User* user = findUserById(userId);
    MyVector<Ticket> tickets = user->getTickets();
    for (size_t i = 0; i < tickets.getSize(); i++)
    {
        tickets[i].print();
        cout << endl;
    }

}

void SystemManager::addSession(Session* session)
{
    sessions.add(session);
}

void SystemManager::addDefaultUser(User* user)
{
    users.add(user);
}
