#include "Movie.h"
#include "DocumantaryMovie.h"

DocumentaryMovie::DocumentaryMovie(MyString& title, int rate, double duration, int productYear, MyString& Genre, Hall& hall, tm& timeInfo, int startHour, int endHour, bool hasComedyElements)
	:Movie(title, rate, duration, productYear, Genre, hall, timeInfo, startHour, endHour), hasComedyElements(hasComedyElements)
{
}

DocumentaryMovie::DocumentaryMovie(MyString& title, int rate, double duration, int productYear, MyString& Genre, bool hasComedyElements)
	:Movie(title, rate, duration, productYear, Genre), hasComedyElements(hasComedyElements)
{
}

bool DocumentaryMovie::getHasComedyElements() const
{
	return hasComedyElements;
}