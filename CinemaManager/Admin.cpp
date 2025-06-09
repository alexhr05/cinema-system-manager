#include "User.h"
#include "Admin.h"
#include "Movie.h"
#include "ActionMovie.h"
#include "DocumantaryMovie.h"
#include "DramaMovie.h"
#include "SystemManager.h"

Admin::Admin(MyString name, MyString password)
    : User(name, password, 0.0) {
    
}


void Admin::addActionMovie(SystemManager& system,Movie* movie, int actionIntensity)
{
    ActionMovie* action = dynamic_cast<ActionMovie*>(movie);
    action->setActionIntensity(actionIntensity);

    system.addMovie(action);
}

void Admin::addDramaMovie(SystemManager& system, Movie* movie, bool hasComedyElements)
{
    DramaMovie* drama = dynamic_cast<DramaMovie*>(movie);
    drama->setHasComedyElements(hasComedyElements);

    system.addMovie(drama);
}

void Admin::addDocumentaryMovie(SystemManager& system, Movie* movie, bool isBasedOnTrueEvents)
{
    DocumentaryMovie* documentary = dynamic_cast<DocumentaryMovie*>(movie);
    documentary->setIsBasedOnTrueEvents(isBasedOnTrueEvents);

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

void Admin::removeMovie(SystemManager& system, Movie* movie)
{
    system.removeMovieSystem(movie);
}

void Admin::addHall(SystemManager& system, Hall* hall)
{
    system.addHall(hall);
}

void Admin::removeHall(SystemManager& system, Hall* hall)
{
    system.removeHallSystem(hall);
}


