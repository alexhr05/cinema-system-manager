#pragma once

#include "User.h"
#include "Movie.h"
#include "SystemManager.h"

class Admin : public User {
public:
	Admin(MyString name, MyString password);

	void handleUserSpecificCommand(MyString command, SystemManager& system);

	void addActionMovie(Movie& movie, int actionIntensity);
	void addDramaMovie(Movie& movie, bool hasComedyElements);
	void addDocumentaryMovie(Movie& movie, bool isBasedOnTrueEvents);


};