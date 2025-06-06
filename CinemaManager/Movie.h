#pragma once

#include "MyString.h"
#include "Hall.h"
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
	Hall hall;
	tm timeInfo = {};
	int  startHour;
	int endHour;
public:
	Movie();
	Movie(MyString& title, int rate, double duration, int productYear, MyString& Genre, Hall& hall, tm& timeInfo, int startHour, int endHour);
	Movie(MyString& title, int rate, double duration, int productYear, MyString& Genre);

	int getId() const;
	MyString getTitle() const;
	int getRate() const;
	double getDuration() const;
	int getProductionYear() const;
	MyString getGenre() const;
	Hall getHall() const;
	tm getTimeInfo() const;
	int getStartHour() const;
	int getEndHour() const;
	
	virtual double getTicketPrice() const = 0;

};