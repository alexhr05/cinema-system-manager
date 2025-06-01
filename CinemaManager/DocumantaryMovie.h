#pragma once

#include "Movie.h"

class DocumentaryMovie : public Movie {
private:
	bool hasComedyElements;
public:
	DocumentaryMovie(MyString& title, int rate, double duration, int productYear, MyString& Genre, Hall& hall, tm& timeInfo, int startHour, int endHour, bool hasComedyElements);
	DocumentaryMovie(MyString& title, int rate, double duration, int productYear, MyString& Genre, bool hasComedyElements);

	bool getHasComedyElements() const;
};