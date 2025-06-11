#pragma once

#include "MyString.h"
#include "Hall.h"
#include "MyVector.hpp"
#include "MoviesType.h"
#include <ctime>

class Movie {
private:
	static int counterId;
	int id;
	MyString title;
	int rate;
	double duration;
	int productionYear;
	MyString Genre;
	int hallId;
	MyVector<tm> timeInfo;
	int  startHour;
	int endHour;
	MoviesType type;
public:
	Movie();
	Movie(MyString& title, int rate, double duration, int productYear, MyString& Genre, int hallId, MyVector<tm> timeInfo, int startHour, int endHour, MoviesType type);
	Movie(MyString& title, int rate, double duration, int productYear, MyString& Genre, MoviesType type);

	int getId() const;
	MyString getTitle() const;
	int getRate() const;
	double getDuration() const;
	int getProductionYear() const;
	MyString getGenre() const;
	int getHallId() const;
	MyVector<tm> getTimeInfo() const;
	int getStartHour() const;
	int getEndHour() const;
	void setHallId(int id);
	MoviesType getMovieType() const;
	void setMovieType();
	
	virtual double getTicketPrice() const = 0;
	virtual Movie* clone() const = 0;
	

};