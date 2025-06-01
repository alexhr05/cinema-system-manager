#pragma once

#include "Movie.h"

class ActionMovie : public Movie {
private:
	int actionIntensity;
public:
	ActionMovie(MyString& title, int rate, double duration, int productYear, MyString& Genre, Hall& hall, tm& timeInfo, int startHour, int endHour, int actionIntensity);
	ActionMovie(MyString& title, int rate, double duration, int productYear, MyString& Genre, int actionIntensity);

	int getActionIntensity() const;
};