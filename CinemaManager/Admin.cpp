//#include "User.h"
#include "Admin.h"
//#include "Movie.h"
//#include "ActionMovie.h"
//#include "DocumantaryMovie.h"
//#include "DramaMovie.h"
//#include "SystemManager.h"



Admin::Admin(MyString name, MyString password, double balance)
    : User(name, password, balance) {
    
}


void Admin::addActionMovie(SystemManager& system, ActionMovie* action)
{
    system.addMovie(action);
}

void Admin::addDramaMovie(SystemManager& system, DramaMovie* drama)
{
    system.addMovie(drama);
}

void Admin::addDocumentaryMovie(SystemManager& system, DocumentaryMovie* documentary)
{
    cout << "minava dobaven"<<endl;
    system.addMovie(documentary);
}

void Admin::handleUserSpecificCommand(MyString command, SystemManager& system)
{
    //if (cmd == "add-movie") {
    //    std::cout << "[Admin] Adding movie...\n";
    //    // addMovie();
    //}
    //else if (cmd == "remove-movie") {
    //    std::cout << "[Admin] Removing movie...\n";
    //    // removeMovie();
    //}
    //else if (cmd == "open-haul") {
    //    std::cout << "[Admin] Opening hall...\n";
    //    // openHaul();
    //}
    //else if (cmd == "close-haul") {
    //    std::cout << "[Admin] Closing hall...\n";
    //    // closeHaul();
    //}
}

void Admin::removeMovie(SystemManager& system, int movieId)
{
    system.removeMovieSystem(movieId);
}

void Admin::addHall(SystemManager& system, Hall* hall)
{
    system.addHall(hall);
}

void Admin::removeHall(SystemManager& system, Hall* hall)
{
    system.removeHallSystem(hall);
}


