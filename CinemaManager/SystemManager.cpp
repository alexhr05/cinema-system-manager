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



SystemManager::SystemManager(): users(MyVector<User*>()), movies(MyVector<Movie*>()), halls(MyVector<Hall*>())
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

void SystemManager::loadUsersFromFiles()
{
    std::ifstream in("users.txt");
    if (!in.is_open()) {
        std::cerr << "Could not open user file. Creating default admin.\n";
        addDefaultAdmin();
        return;
    }

    
    bool adminExists = false;
    while (!in.eof()) {
        int id;
        MyString name, password;
        double balance;
        in >> id >> name >> password >> balance;
        if (id == 1) {
            adminExists = true;
            User* admin = new User(name, password);
            admin->setId(1);
            users.add(admin);
            cout << "Size="<<users.getSize() << endl;
            cout << "Name="<<name.c_str() << endl;
        }
        
    }
    
    
    
    if (!adminExists) {
        addDefaultAdmin();
    }
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
    ofstream outFile("users.txt", ios::app);
    if (!outFile.is_open()) return;

    cout << "users.getSIze()" << users.getSize();
    for (size_t i = 0; i < users.getSize(); i++) {
        User* user = users[i];
        outFile << user->getId() << "\n"
            << user->getName().c_str() << '\n'
            << user->getPassword().c_str() << '\n'
            << user->getBalance() << '\n';

        saveTicketsForUser(user);
    }
    outFile.close();
}

void SystemManager::saveTicketsForUser(User* user) {
    char idBuffer[12]; 
    
    MyString::intToCharArray(user->getId(), idBuffer); 

    MyString idStr(idBuffer); 

    MyString name = "ticketUser";

    MyString nameBeforeDot = name + idStr;
    MyString nameAfterDot = ".txt";
   

    MyString fileName = nameBeforeDot + nameAfterDot;
    ofstream outFile(fileName.c_str(), ios::app);

    MyVector<Ticket> userTickets = user->getTickets();
    
    
    for (size_t i = 0; i < userTickets.getSize(); i++)
    {
        outFile << userTickets[i].getMovie()->getId() << "\n"
            << userTickets[i].getRow() << "\n"
            << userTickets[i].getCol() << "\n"
            << userTickets[i].getIssueDate() << "\n";
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

    int id, productionYear, starHour, endHour, rate, hallId;
    double duration;
    MyString title, genre;
    int type;
    int actionIntensity;
    bool isBasedOnTrueEvents, hasComedyElements;
    tm timeStruct = {};

    while (in >> id >> type) {
        in.ignore();
        getline(in, title, '"');

        in >> rate >> duration >> productionYear;

        in.ignore();
        getline(in, genre, '"');

        in >> hallId >> timeStruct.tm_year >> timeStruct.tm_mon >> timeStruct.tm_mday >> starHour >> endHour;
        Movie* movie = nullptr;

        MoviesType movieType = static_cast<MoviesType>(type);

        Hall* h = findHallById(hallId);
        if (!h) {
            cout << "Hall not found with this id:" << hallId << endl;
            continue;
        }

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
        movies.add(movie);
        cout << "Minava";
        cout << movies[0]->getTitle().c_str() <<" " << movies[0]->getProductionYear();
        
        in.close();
    }
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
            << (1900 + timeStruct.tm_year) << "\n"
            << (1 + timeStruct.tm_mon) << "\n"
            << timeStruct.tm_mday << "\n"
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
