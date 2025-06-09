#include "SystemManager.h"
#include <iostream>
#include <fstream>
#include "MyVector.hpp"
#include "SeatTypes.h"
#include "User.h"
#include "Admin.h"
#include "MoviesType.h"
#include "ActionMovie.h"
#include "DocumantaryMovie.h"
#include "DramaMovie.h"


using namespace std;



SystemManager::SystemManager(): users(MyVector<User*>()), movies(MyVector<Movie*>()), halls(MyVector<Hall*>()),  allTickets(MyVector<Ticket>())
{
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
}

void SystemManager::loadHallsFromFiles()
{
    
    std::ifstream inFile("halls.txt");
    if (!inFile.is_open()) return;

    int id, rows, cols;
    cout << "Minava" << endl;
    while (inFile >> id >> rows >> cols) {
        cout << "id=" << id<<endl;

        cout << "rows=" << rows<<endl;

        cout << "cols=" << cols << endl;
        
        //Hall h(rows, cols);
        Hall* h = new Hall(rows, cols);
        h->allocateSeats();
        h->setId(id);
        MyString word;
        for (int i = 0; i < rows; i++){   
            inFile.ignore();
            for (int j = 0; j < cols; j++) {
                SeatTypes type = static_cast<SeatTypes>(inFile.get());
                if (type == SeatTypes::Reserved) {
                    h->reserveSeat(i,j);
                }
            }
        }  
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
        for (int j = 0; j < halls[i]->getRows(); j++) {
            for (int q = 0; q < halls[i]->getCols(); q++) {
                outFile << halls[i]->getSeat(j,q);
            }
            outFile << "\n";
        }
    }
    outFile.close();
}

void SystemManager::printHalls() {
    
    for (size_t i = 0; i < halls.getSize(); i++) {
        Hall* h = halls[i];
        Hall hall = *h;
        cout << "Hall #" << h->getId() << ":\n";
        hall.displaySeats();
        cout << "\n";
    }
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

void SystemManager::loadTcketsFromFiles() {
    ifstream in("tickets.txt");
    if (!in.is_open()) {
        std::cerr << "Could not open tickets file"<<endl;
        return;
    }
    int id, movieId, row, col, year, month, day, hour;
    tm issuedDate;


    while (in>>id>>movieId>> row>>col>>year>>month>>day>>hour) {
        issuedDate = createTimeStruct(year, month, day, hour);
        
        try {
            /*MyString name = "asdawd";
            MyString gen = "gen";
            Movie* movie = new ActionMovie(name, 3, 2.5, 2000, gen, MoviesType::ActionMovie, 15);
            movies.add(movie);*/
            /*cout << "Moive id:" << movies[0]->getId() << "movieId" << movieId << "row:" << row << "; col=" << col << "; year:" << issuedDate.tm_year << "; month:" << issuedDate.tm_mon << endl;*/
            cout << "Movies:" << movies.getSize()<<endl;
            Movie* movieRes = findMovieById(movieId);
            Ticket tick(movieRes, row, col);
            tick.setIssuedDate(issuedDate);

            
            allTickets.add(tick);
            
        }
        catch (const std::exception& ex) {
            std::cerr << "Error: " << ex.what() << std::endl;
            break;
        }
        

        
    }
    

    in.close();
}

void SystemManager::saveTicketsToFiles() {
    ofstream outFile("tickets.txt", ios::app);
    if (!outFile.is_open()) return;
    MyString name = "asdawd";
    MyString gen = "gen";
    Movie* movie = new ActionMovie(name, 3, 2.5, 2000, gen, MoviesType::ActionMovie, 15);
    int row = 2;
    
    Ticket ticks(movie, 2, 4);
    tm time = {};
    time.tm_year = 2025;
    time.tm_mon = 2;
    time.tm_wday = 15;
    time.tm_hour = 9;
    ticks.setIssuedDate(time);
    allTickets.add(ticks);
    for (size_t i = 0; i < allTickets.getSize(); i++) {
        Ticket ticket = allTickets[i];

        tm issueDate = ticket.getIssueDate();
        outFile << ticket.getId() << "\n"
            << ticket.getMovie()->getId() << '\n'
            << ticket.getRow() << '\n'
            << ticket.getCol() << '\n'
            << issueDate.tm_year << '\n'
            << issueDate.tm_mon << '\n'
            << issueDate.tm_wday << '\n'
            << issueDate.tm_hour << '\n';

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

        in.ignore();
        getline(in, password, '\n');

        in >> balance>> ticketsSize;
        
        User* user = new User(name, password, balance);
        for (size_t i = 0; i < ticketsSize; i++) {
            in >> ticketId;
            try {
                Ticket ticket = findTicketById(ticketId);
                allTickets.add(ticket);
                user->addTicket(ticket);
            }
            catch (const std::exception& ex) {
                std::cerr << "Error: " << ex.what() << std::endl;
            } 
        }

        in >> watchedMoviesSize;

        for (size_t i = 0; i < watchedMoviesSize; i++) {
            in >> watchedMovieId;
            try {
                Movie* movie = findMovieById(watchedMovieId);
                user->addWatchedMovies(movie);
            }
            catch (const std::exception& ex) {
                std::cerr << "Error: " << ex.what() << std::endl;
            }
        }
        users.add(user);
        cout << "USER INFO:" << users.getSize()<< endl;
        cout << users[1]->getName().c_str() << " " << users[1]->getPassword().c_str() << " " << users[1]->getBalance() << " "
            << users[1]->getTickets()[0].getId();
        
    }
   
    in.close();
}

Ticket& SystemManager::findTicketById(int id) {
    for (int i = 0; i < allTickets.getSize(); i++) {
        
        if (allTickets[i].getId() == id) {
            return allTickets[i]; 
        }
        
    }

    throw std::runtime_error("Ticket not found");
}

Movie* SystemManager::findMovieById(int id) {
    
    for (int i = 0; i < movies.getSize(); i++) {
        cout << movies.getSize() << ":SIZE" << endl;
        if (movies[i]->getId() == id) {
            return movies[i];
        }
        
    }

    throw std::runtime_error("Movie not found");
}

void SystemManager::addDefaultAdmin() {
    MyString defaultName = "admin";
    MyString defaultPassword = "admin123";
    User* admin = new User(defaultName, defaultPassword);
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
            if (user->getTickets().getSize() > 0) {
                MyVector<Ticket> tickets;
                tickets = user->getTickets();
                outFile << tickets.getSize() << "\n";
                for (size_t j = 0; j < tickets.getSize(); j++) {
                    outFile << tickets[j].getId() << "\n";
                }
            }
            if (user->getWatchedMovies().getSize() > 0) {
                MyVector<Movie*> watchedMovies;
                watchedMovies = user->getWatchedMovies();
                for (size_t j = 0; j < watchedMovies.getSize(); j++) {
                    outFile << watchedMovies[j]->getId() << "\n";
                }
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
        year, month, day, hour;
    
    double duration;
    MyString title, genre;
    
    
    bool isBasedOnTrueEvents, hasComedyElements;
    

    while (in >> id >> type) {
        in.ignore();
        cout << "MovieId:" << id<<endl;
        
        getline(in, title, '\n');
        
        in >> rate >> duration >> productionYear;
        cout << "rate"<<rate;
        in.ignore();
        getline(in, genre, '\n');
        tm timeStruct = {};
        in >> hallId >> year >> month >> day >> hour >> startHour >> endHour;
        Movie* movie = nullptr;
        timeStruct.tm_year = year; 
        timeStruct.tm_mon = month - 1;     
        timeStruct.tm_mday = day;
        timeStruct.tm_hour = hour;

        MoviesType movieType = static_cast<MoviesType>(type);

        Hall* h = findHallById(hallId);
        if (!h) {
            cout << "Hall not found with this id:" << hallId << endl;
            continue;
        }

        switch (movieType) {
        case MoviesType::ActionMovie:
            in >> actionIntensity;
            
            movie = new ActionMovie(title, rate, duration, productionYear, genre,hallId, timeStruct, startHour, endHour, movieType, actionIntensity);
            break;
        case MoviesType::DocumentaryMovie:
            in >> isBasedOnTrueEvents;
            movie = new DocumentaryMovie(title, rate, duration, productionYear, genre, hallId, timeStruct, startHour, endHour, movieType, isBasedOnTrueEvents);
            break;
        case MoviesType::DramaMovie:
            in >> hasComedyElements;
            movie = new DramaMovie(title, rate, duration, productionYear, genre, hallId, timeStruct, startHour, endHour, movieType, hasComedyElements);
            break;
        default:
            cout << "Unknown movie type: " << type << endl;
        }
        movies.add(movie);
        cout <<"size:"<< movies.getSize();
        
        
    }
    in.close();
}

void SystemManager::saveMoviesToFile()
{

    ofstream outFile("movies.txt", ios::app);
    MyString name = "Star wars";
    MyString gen = "fic";
    Movie* movie = new ActionMovie(name, 3, 2.5, 2000, gen, MoviesType::ActionMovie,15);
    movie->setHallId(2);
    movies.add(movie);
    tm timeStruct = {};
    timeStruct = movie->getTimeInfo();
    for (size_t i = 0; i < movies.getSize(); i++)
    {
        outFile << movies[i]->getId() << "\n"
            << static_cast<int>(movies[i]->getMovieType())<<"\n"
            << movies[i]->getTitle().c_str() << "\n"
            << movies[i]->getRate() << "\n"
            << movies[i]->getDuration() << "\n"
            << movies[i]->getProductionYear() << "\n"
            << movies[i]->getGenre().c_str() << "\n"
            << movies[i]->getHallId() << "\n"
            << movies[i]->getTimeInfo().tm_year << "\n"
            << movies[i]->getTimeInfo().tm_mon << "\n"
            << movies[i]->getTimeInfo().tm_wday << "\n"
            << movies[i]->getTimeInfo().tm_hour << "\n"
            << movies[i]->getStartHour() << "\n"
            << movies[i]->getEndHour()<<"\n";
        
        switch (movies[i]->getMovieType()) {
        case MoviesType::ActionMovie: {
            ActionMovie* action = dynamic_cast<ActionMovie*>(movie);
            outFile << action->getActionIntensity() << "\n";
            break;
        }   
        case MoviesType::DocumentaryMovie: {
            DocumentaryMovie* documentary = dynamic_cast<DocumentaryMovie*>(movie);
            outFile << documentary->getIsBasedOnTrueEvents() << "\n";
            break;
        }   
        case MoviesType::DramaMovie: {
            DramaMovie* drama = dynamic_cast<DramaMovie*>(movie);
            outFile << drama->getHasComedyElements() << "\n";
            break;
        }
        default:
            cout << "Unknown movie type: " << static_cast<int>(movies[i]->getMovieType())<< endl;
        }
            
    }


    outFile.close();
}

User* SystemManager::login(MyString name, MyString password) {

    for (size_t i = 0; i < users.getSize(); i++) {
        cout << "users[i]->getId()=" << users[i]->getId() << endl;
        cout << "users[i]->getPassword()=" << users[i]->getPassword().c_str() << endl;
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

bool SystemManager::registerUser(MyString name, MyString password) {
    for (size_t i = 0; i < users.getSize(); i++)
    {
        if(users[i]->getName().equals(name) && users[i]->getPassword().equals(password)) {
            return false;
        }
    }

    User* user = new User(name, password);
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
