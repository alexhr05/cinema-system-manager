#pragma once

#include "Movie.h"

class DramaMovie : public Movie {
private:
	bool hasComedyElements;
	const double basePrice = 7.0;
public:
	DramaMovie(MyString& title, int rate, double duration, int productYear, MyString& Genre, Hall& hall, tm& timeInfo, int startHour, int endHour, bool isBasedOnTrueEvents);
	DramaMovie(MyString& title, int rate, double duration, int productYear, MyString& Genre, bool isBasedOnTrueEvents);

	bool getHasComedyElements() const;
	double getTicketPrice() const override;

	Movie* clone() const override {
		return new DramaMovie(*this);
	}
};