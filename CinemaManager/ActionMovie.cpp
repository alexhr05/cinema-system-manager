#include "Movie.h"
#include "MoviesType.h"
#include "ActionMovie.h"

ActionMovie::ActionMovie(MyString& title, int rate, double duration, int productYear, MyString& Genre, int hallId, tm& timeInfo, int startHour, int endHour, MoviesType type, int actionIntensity)
	:Movie(title,rate, duration, productYear, Genre, hallId, timeInfo, startHour, endHour, type), actionIntensity(actionIntensity)
{
	
}

ActionMovie::ActionMovie(MyString& title, int rate, double duration, int productYear, MyString& Genre, MoviesType type, int actionIntensity)
	:Movie(title, rate, duration, productYear, Genre, type), actionIntensity(actionIntensity)
{
	
}

ActionMovie::ActionMovie(const ActionMovie& other) : Movie(other)
{
	this->actionIntensity = other.actionIntensity;
}

int ActionMovie::getActionIntensity() const
{
	return actionIntensity;
}

double ActionMovie::getTicketPrice() const
{
	return basePrice + (actionIntensity * 1.5);
}

Movie* ActionMovie::clone() const
{
	
	return new ActionMovie(*this);
	
}
