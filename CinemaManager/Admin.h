#pragma once

#include "User.h"
#include "Movie.h"
#include "ActionMovie.h"
#include "DocumantaryMovie.h"
#include "DramaMovie.h"
#include "SystemManager.h"

class SystemManager;

class Admin : public User {
public:
	Admin(MyString name, MyString password,double balance);

	void handleUserSpecificCommand(MyString command, SystemManager& system);

	void addActionMovie(SystemManager& system,ActionMovie* action);
	void addDramaMovie(SystemManager& system, DramaMovie* dramaa);
	void addDocumentaryMovie(SystemManager& system, DocumentaryMovie* documentary);
	void removeMovie(SystemManager& system, int movieId);

	void addHall(SystemManager& system, Hall* hall);
	void removeHall(SystemManager& system, Hall* hall);
	

};