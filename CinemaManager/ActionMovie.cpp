#include "Movie.h"
#include "ActionMovie.h"

ActionMovie::ActionMovie(MyString& title, int rate, double duration, int productYear, MyString& Genre, Hall& hall, tm& timeInfo, int startHour, int endHour, int actionIntensity)
	:Movie(title,rate, duration, productYear, Genre, hall, timeInfo, startHour, endHour), actionIntensity(actionIntensity)
{
}

ActionMovie::ActionMovie(MyString& title, int rate, double duration, int productYear, MyString& Genre, int actionIntensity)
	:Movie(title, rate, duration, productYear, Genre), actionIntensity(actionIntensity)
{
}

int ActionMovie::getActionIntensity() const
{
	return actionIntensity;
}
