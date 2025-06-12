#include "Movie.h"
#include "MoviesType.h"
#include "ActionMovie.h"
#include <iostream>

using namespace std;

//ActionMovie::ActionMovie(MyString& title, int rate, double duration, int productYear, MyString& Genre, int hallId, MyVector<tm> timeInfo, int startHour, int endHour, MoviesType type, int actionIntensity)
//	:Movie(title,rate, duration, productYear, Genre, hallId, timeInfo, startHour, endHour, type), actionIntensity(actionIntensity)
//{
//	
//}

ActionMovie::ActionMovie(MyString& title, int rate, double duration, int productYear, MyString& Genre, MoviesType type, int actionIntensity)
	:Movie(title, rate, duration, productYear, Genre, type), actionIntensity(actionIntensity)
{
	
}

ActionMovie::ActionMovie(const ActionMovie& other) : Movie(other)
{
	this->actionIntensity = other.actionIntensity;
}

void ActionMovie::setActionIntensity(int actionIntensity)
{
	if (actionIntensity < 0 || actionIntensity > 20)
		cout << "ActionIntensity is not in the interval between 0 and 20";
		return;

	this->actionIntensity = actionIntensity;
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
