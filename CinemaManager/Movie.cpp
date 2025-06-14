#include "Movie.h"
#include "MyVector.hpp"

Movie::Movie(): id(++counterId), title(""), rate(0), duration(0), productionYear(0), Genre(""), type()//, hallId(0), timeInfo(MyVector<tm>()), startHour(0), endHour(0)
{
}

//Movie::Movie(MyString& title, int rate, double duration, int productYear, MyString& Genre, int hallId, MyVector<tm> timeInfo, int startHour, int endHour, MoviesType type)
//	: id(++counterId), title(title), rate(rate), duration(duration), productionYear(productYear), Genre(Genre), hallId(hallId), timeInfo(timeInfo), startHour(startHour), endHour(endHour), type(type)
//{
//}

Movie::Movie(MyString& title, int rate, double duration, int productYear, MyString& Genre, MoviesType type)
	 : id(++counterId),title(title), rate(rate), duration(duration), productionYear(productYear), Genre(Genre), type(type)
{
	
}

void Movie::setId(int newId)
{
	id = newId;
	if (newId >= counterId) {
		counterId = newId + 1;
	}
}

void Movie::setTitle(MyString title) {
	this->title = title;
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

//int Movie::getHallId() const
//{
//	return hallId;
//}
//
//MyVector<tm> Movie::getTimeInfo() const
//{
//	return timeInfo;
//}
//
//int Movie::getStartHour() const
//{
//	return startHour;
//}
//
//int Movie::getEndHour() const
//{
//	return endHour;
//}
//
//void Movie::setHallId(int id)
//{
//	hallId = id;
//}

MoviesType Movie::getMovieType() const
{
	return type;
}



bool Movie::operator==(const Movie* other)
{
	return this->getId() == other->getId();
}
