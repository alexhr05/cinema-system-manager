﻿#pragma once

#include "Movie.h"

class DocumentaryMovie : public Movie {
private:
	bool isBasedOnTrueEvents;
	const double basePrice = 5.0;
public:

	DocumentaryMovie(MyString title, int rate, double duration, int productYear, MyString Genre, MoviesType type, bool isBasedOnTrueEvents);
	

	void setIsBasedOnTrueEvents(bool isBasedOnTrueEvents);

	bool getIsBasedOnTrueEvents() const;
	double getTicketPrice() const override;
	void print() override;

	Movie* clone() const override;
};