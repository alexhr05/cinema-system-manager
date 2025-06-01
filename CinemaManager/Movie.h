#pragma once

#include "MyString.h"
#include "Hall.h"
#include <ctime>

class Movie {
private:
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
	Movie(MyString& title, int rate, double duration, int productYear, MyString& Genre, Hall& hall, tm& timeInfo, int startHour, int endHour);
	Movie(MyString& title, int rate, double duration, int productYear, MyString& Genre);


	MyString getTitle();
	int getRate();
	double getDuration();
	int getProductionYear();
	MyString getGenre();
	Hall getHall();
	tm getTimeInfo();
	int getStartHour();
	int getEndHour();
	


};