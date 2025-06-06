#include "Movie.h"

Movie::Movie(): id(++counterId), title(""), rate(0), duration(0), productionYear(0), Genre(""), hall(), timeInfo(), startHour(0), endHour(0)
{
}

Movie::Movie(MyString& title, int rate, double duration, int productYear, MyString& Genre, Hall& hall, tm& timeInfo, int startHour, int endHour)
	: id(++counterId), title(title), rate(rate), duration(duration), productionYear(productYear), Genre(Genre), hall(hall), timeInfo(timeInfo), startHour(startHour), endHour(endHour)
{
}

Movie::Movie(MyString& title, int rate, double duration, int productYear, MyString& Genre)
	: id(++counterId),title(title), rate(rate), duration(duration), productionYear(productYear), Genre(Genre), hall(Hall(3,3))
{
}

int Movie::getId() const
{
	return id;
}
int Movie::counterId = 1;

MyString Movie::getTitle() const
{
	return title;
}

int Movie::getRate() const
{
	return rate;
}

double Movie::getDuration() const
{
	return duration;
}

int Movie::getProductionYear() const
{
	return productionYear;
}

MyString Movie::getGenre() const
{
	return Genre;
}

Hall Movie::getHall() const
{
	return hall;
}

tm Movie::getTimeInfo() const
{
	return timeInfo;
}

int Movie::getStartHour() const
{
	return startHour;
}

int Movie::getEndHour() const
{
	return endHour;
}