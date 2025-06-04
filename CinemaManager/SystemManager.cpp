#include "SystemManager.h"
#include <iostream>
#include <fstream>
#include "MyVector.hpp"
#include "SeatTypes.h"

using namespace std;



SystemManager::SystemManager(): users(MyVector<User>()), movies(MyVector<Movie>()), halls(MyVector<Hall>())
{
}

void SystemManager::loadHallsFromFiles()
{
    std::ifstream inFile("halls.txt");
    if (!inFile.is_open()) return;

    int id, rows, cols;
    while (inFile >> id >> rows >> cols) {
        cout << "id=" << id<<endl;

        cout << "rows=" << rows<<endl;

        cout << "cols=" << cols << endl;
        cout << "Minava"<<endl;
        Hall h(rows, cols);
        h.allocateSeats();
        h.setId(id);
        MyString word;
        
        for (int i = 0; i < rows; i++){   
            inFile.ignore();
            for (int j = 0; j < cols; j++) {
                SeatTypes type = static_cast<SeatTypes>(inFile.get());
                if (type == SeatTypes::Reserved) {
                    h.reserveSeat(i,j);
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
        Hall& h = halls[i];
        outFile << h.getId() << "\n"
            << h.getRows() << '\n'
            << h.getCols() << '\n';
        for (int j = 0; j < halls[i].getRows(); j++) {
            for (int q = 0; q < halls[i].getCols(); q++) {
                outFile << halls[i].getSeat(j,q);
            }
            outFile << "\n";
        }
    }
    outFile.close();
}

void SystemManager::printHalls() {
    
    for (size_t i = 0; i < halls.getSize(); i++) {
        Hall h = halls[i];
        cout << "Hall #" << h.getId() << ":\n";
        h.displaySeats();
        cout << "\n";
    }
}

void SystemManager::loadUsersFromFiles()
{
}

void SystemManager::saveUsersToFiles()
{
}

void SystemManager::loadMoviesFromFiles()
{
}

void SystemManager::saveMoviesToFiles()
{
}

void SystemManager::addMovie(Movie& movie)
{
    movies.add(movie);
}

void SystemManager::addHall(const Hall& hall)
{
    halls.add(hall);
}

MyVector<User> SystemManager::getUsers() const
{
    return users;
}

MyVector<Movie> SystemManager::getMovies() const
{
    return movies;
}

MyVector<Hall> SystemManager::getHalls() const
{
    return halls;
}


