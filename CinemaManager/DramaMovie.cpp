#include "Movie.h"
#include "DramaMovie.h"

DramaMovie::DramaMovie(MyString& title, int rate, double duration, int productYear, MyString& Genre, Hall& hall, tm& timeInfo, int startHour, int endHour, bool hasComedyElements)
	:Movie(title, rate, duration, productYear, Genre, hall, timeInfo, startHour, endHour), hasComedyElements(hasComedyElements)
{
}

DramaMovie::DramaMovie(MyString& title, int rate, double duration, int productYear, MyString& Genre, bool hasComedyElements)
	:Movie(title, rate, duration, productYear, Genre), hasComedyElements(hasComedyElements)
{
}

bool DramaMovie::getHasComedyElements() const
{
	return hasComedyElements;
}
