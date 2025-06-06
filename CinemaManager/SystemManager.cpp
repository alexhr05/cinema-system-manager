#include "SystemManager.h"
#include <iostream>
#include <fstream>
#include "MyVector.hpp"
#include "SeatTypes.h"
#include "Admin.h"

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
    users.add(new Admin("admin", "admin123"));

}

void SystemManager::saveUsersToFiles()
{
    ofstream outFile("users.txt", ios::app);
    if (!outFile.is_open()) return;

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
    /*delete[] idBuffer;*/
}

void SystemManager::loadMoviesFromFiles()
{
}

void SystemManager::saveMoviesToFiles()
{
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


