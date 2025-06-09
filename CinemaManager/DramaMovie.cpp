#include "Movie.h"
#include "DramaMovie.h"

DramaMovie::DramaMovie(MyString& title, int rate, double duration, int productYear, MyString& Genre, int hallId, MyVector<tm> timeInfo, int startHour, int endHour, MoviesType type, bool hasComedyElements)
	:Movie(title, rate, duration, productYear, Genre, hallId, timeInfo, startHour, endHour, type), hasComedyElements(hasComedyElements)
{
}

DramaMovie::DramaMovie(MyString& title, int rate, double duration, int productYear, MyString& Genre, MoviesType type, bool hasComedyElements)
	:Movie(title, rate, duration, productYear, Genre, type), hasComedyElements(hasComedyElements)
{
}

void DramaMovie::setHasComedyElements(bool hasComedyElements)
{
	this->hasComedyElements = hasComedyElements;
}

bool DramaMovie::getHasComedyElements() const
{
	return hasComedyElements;
}

double DramaMovie::getTicketPrice() const 
{
	return basePrice + (hasComedyElements ? 2.0 : 0.0);
}

Movie* DramaMovie::clone() const
{
	
	return new DramaMovie(*this);
	
}
