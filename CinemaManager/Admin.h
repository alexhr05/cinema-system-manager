#pragma once

#include "User.h"
#include "Movie.h"
#include "ActionMovie.h"
#include "DocumantaryMovie.h"
#include "DramaMovie.h"
#include "SystemManager.h"

class SystemManager;

class Admin : public User {
private:
	void handleUserSpecificCommand(SystemManager& system, MyString cmd) override;
public:
	Admin(MyString name, MyString password,double balance);

	

	void addActionMovie(SystemManager& system,ActionMovie* action);
	void addDramaMovie(SystemManager& system, DramaMovie* dramaa);
	void addDocumentaryMovie(SystemManager& system, DocumentaryMovie* documentary);
	void removeMovie(SystemManager& system, int movieId);

	void addHall(SystemManager& system, Hall* hall);
	void addNewSession(SystemManager& system,  Session* session);
	void removeHall(SystemManager& system, int hallId);

	void addUser(SystemManager& system, User* user);
	void removeUser(SystemManager& system, int userId);
	void updateTitleMovie(SystemManager& system, int movieId,MyString title);
	
	void printUsersWatchedMovies(SystemManager& system,int userId);
	void printUsersTickets(SystemManager& system, int userId);
};