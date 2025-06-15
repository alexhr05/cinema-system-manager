#include "Movie.h"
#include "MyVector.hpp"

// Конструктор по подразбиране
Movie::Movie(): id(++counterId), title(""), rate(0), duration(0), productionYear(0), Genre(""), type()
{
}

// Конструктор с параметри
Movie::Movie(MyString& title, int rate, double duration, int productYear, MyString& Genre, MoviesType type)
	 : id(++counterId),title(title), rate(rate), duration(duration), productionYear(productYear), Genre(Genre), type(type)
{
	
}

// Задава ръчно ID на филма, използва се при зареждане от файл.
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


// Връща типа на филма (1-Action, 2-Drama, 3-Documentary)
MoviesType Movie::getMovieType() const
{
	return type;
}

// Проверява дали два филма са равни (по ID).
bool Movie::operator==(const Movie* other)
{
	return this->getId() == other->getId();
}
