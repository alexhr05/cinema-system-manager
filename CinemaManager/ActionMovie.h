#pragma once

#include "Movie.h"

class ActionMovie : public Movie {
private:
	int actionIntensity;
	const double basePrice = 9.0;
public:
	ActionMovie(MyString& title, int rate, double duration, int productYear, MyString& Genre, int hallId, tm& timeInfo, int startHour, int endHour, MoviesType type, int actionIntensity);
	ActionMovie(MyString& title, int rate, double duration, int productYear, MyString& Genre, MoviesType type, int actionIntensity);
	ActionMovie(const ActionMovie& other);

	int getActionIntensity() const;
	double getTicketPrice() const override;

	Movie* clone() const override;
};