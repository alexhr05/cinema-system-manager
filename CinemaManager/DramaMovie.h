﻿#pragma once

#include "Movie.h"

class DramaMovie : public Movie {
private:
	bool hasComedyElements;
	const double basePrice = 7.0;
public:
	DramaMovie(MyString& title, int rate, double duration, int productYear, MyString& Genre, MoviesType type, bool isBasedOnTrueEvents);

	void setHasComedyElements(bool hasComedyElements);

	bool getHasComedyElements() const;
	double getTicketPrice() const override;
	void print() override;

	Movie* clone() const override;
};