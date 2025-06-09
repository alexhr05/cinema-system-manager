#pragma once

#include "User.h"
#include "Movie.h"
#include "SystemManager.h"

class Admin : public User {
public:
	Admin(MyString name, MyString password);

	void handleUserSpecificCommand(MyString command, SystemManager& system);

	void addActionMovie(SystemManager& system,Movie* movie, int actionIntensity);
	void addDramaMovie(SystemManager& system, Movie* movie, bool hasComedyElements);
	void addDocumentaryMovie(SystemManager& system, Movie* movie, bool isBasedOnTrueEvents);
	void removeMovie(SystemManager& system, Movie* movie);

	void addHall(SystemManager& system, Hall* hall);
	void removeHall(SystemManager& system, Hall* hall);
	

};