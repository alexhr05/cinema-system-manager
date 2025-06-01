#include "Movie.h"

Movie::Movie(MyString& title, int rate, double duration, int productYear, MyString& Genre, Hall& hall, tm& timeInfo, int startHour, int endHour)
	: title(title), rate(rate), duration(duration), productionYear(productYear), Genre(Genre), hall(hall), timeInfo(timeInfo), startHour(startHour), endHour(endHour)
{
}

Movie::Movie(MyString& title, int rate, double duration, int productYear, MyString& Genre)
	: title(title), rate(rate), duration(duration), productionYear(productYear), Genre(Genre), hall("")
{
}

MyString Movie::getTitle()
{
	return title;
}

int Movie::getRate()
{
	return rate;
}

double Movie::getDuration()
{
	return duration;
}

int Movie::getProductionYear()
{
	return productionYear;
}

MyString Movie::getGenre()
{
	return Genre;
}

Hall Movie::getHall()
{
	return hall;
}

tm Movie::getTimeInfo()
{
	return timeInfo;
}

int Movie::getStartHour()
{
	return startHour;
}

int Movie::getEndHour()
{
	return endHour;
}

