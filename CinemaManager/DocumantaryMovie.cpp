#include "Movie.h"
#include "DocumantaryMovie.h"

DocumentaryMovie::DocumentaryMovie(MyString title, int rate, double duration, int productYear, MyString Genre, int hallId, tm& timeInfo, int startHour, int endHour, MoviesType type, bool isBasedOnTrueEvents)
	:Movie(title, rate, duration, productYear, Genre, hallId, timeInfo, startHour, endHour, type), isBasedOnTrueEvents(isBasedOnTrueEvents)
{
}

DocumentaryMovie::DocumentaryMovie(MyString title, int rate, double duration, int productYear, MyString Genre, MoviesType type, bool isBasedOnTrueEvents)
	:Movie(title, rate, duration, productYear, Genre, type), isBasedOnTrueEvents(isBasedOnTrueEvents)
{
}

bool DocumentaryMovie::getIsBasedOnTrueEvents() const
{
	return isBasedOnTrueEvents;
}

double DocumentaryMovie::getTicketPrice() const {
	return basePrice + (isBasedOnTrueEvents ? 3.0 : 0.0);
}

Movie* DocumentaryMovie::clone() const
{
	
	return new DocumentaryMovie(*this);
	
}
