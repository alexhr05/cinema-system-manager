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
	MoviesType type;
public:
	Movie();
	Movie(MyString& title, int rate, double duration, int productYear, MyString& Genre, MoviesType type);


	void setId(int id);
	void setTitle(MyString title);
	int getId() const;
	MyString getTitle() const;
	int getRate() const;
	double getDuration() const;
	int getProductionYear() const;
	MyString getGenre() const;
	MoviesType getMovieType() const;
	void setMovieType();



	bool operator==(const Movie* other);
	
	virtual void print() = 0;
	virtual double getTicketPrice() const = 0;
	virtual Movie* clone() const = 0;
	

};