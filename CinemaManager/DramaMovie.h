#pragma once

#include "Movie.h"

class DramaMovie : public Movie {
private:
	bool hasComedyElements;
public:
	DramaMovie(MyString& title, int rate, double duration, int productYear, MyString& Genre, Hall& hall, tm& timeInfo, int startHour, int endHour, bool isBasedOnTrueEvents);
	DramaMovie(MyString& title, int rate, double duration, int productYear, MyString& Genre, bool isBasedOnTrueEvents);

	bool getHasComedyElements() const;
};