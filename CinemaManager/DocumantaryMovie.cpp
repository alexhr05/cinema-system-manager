#include "Movie.h"
#include "DocumantaryMovie.h"

DocumentaryMovie::DocumentaryMovie(MyString& title, int rate, double duration, int productYear, MyString& Genre, Hall& hall, tm& timeInfo, int startHour, int endHour, bool isBasedOnTrueEvents)
	:Movie(title, rate, duration, productYear, Genre, hall, timeInfo, startHour, endHour), isBasedOnTrueEvents(isBasedOnTrueEvents)
{
}

DocumentaryMovie::DocumentaryMovie(MyString& title, int rate, double duration, int productYear, MyString& Genre, bool isBasedOnTrueEvents)
	:Movie(title, rate, duration, productYear, Genre), isBasedOnTrueEvents(isBasedOnTrueEvents)
{
}

bool DocumentaryMovie::getIsBasedOnTrueEvents() const
{
	return isBasedOnTrueEvents;
}