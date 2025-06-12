#include "Movie.h"
#include "MyVector.hpp"

Movie::Movie(): id(++counterId), title(""), rate(0), duration(0), productionYear(0), Genre("")//, hallId(0), timeInfo(MyVector<tm>()), startHour(0), endHour(0)
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

void Movie::print()
{
	cout << "Type Movie(1-Action movie; 2-Documentary movie; 3- Drama movie);" << endl;
	cout << "Name: " << title.c_str() << "\n"
		<< "Type Movie: " << static_cast<int>(type) << "\n"
		<< "Rate: " << rate << "\n"
		<< "Duration: " << duration << "\n"
		<< "Production Year: " << productionYear << "\n"
		<< "Genre: " << Genre.c_str() << "\n";
}
