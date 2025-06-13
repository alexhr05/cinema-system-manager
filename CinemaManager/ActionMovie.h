#pragma once

#include "Movie.h"

class ActionMovie : public Movie {
private:
	int actionIntensity;
	const double basePrice = 9.0;
public:
	ActionMovie(MyString& title, int rate, double duration, int productYear, MyString& Genre, MoviesType type, int actionIntensity);
	ActionMovie(const ActionMovie& other);

	void setActionIntensity(int actionIntensity);

	int getActionIntensity() const;
	double getTicketPrice() const override;

	void print() override;
	Movie* clone() const override;
};