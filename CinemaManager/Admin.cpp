#include "User.h"
#include "Admin.h"
#include "SystemManager.h"

Admin::Admin(MyString name, MyString password)
    : User(name, password, 0.0) {
    
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

void Admin::removeMovie(SystemManager& system)
{
    
}

//void Admin::addActionMovie(Movie& movie, int actionIntensity)
//{
//    Action
//}
