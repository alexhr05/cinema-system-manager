#pragma once

#include "Movie.h"

class DocumentaryMovie : public Movie {
private:
	bool isBasedOnTrueEvents;
	const double basePrice = 5.0;
public:
	DocumentaryMovie(MyString& title, int rate, double duration, int productYear, MyString& Genre, Hall& hall, tm& timeInfo, int startHour, int endHour, bool isBasedOnTrueEvents);
	DocumentaryMovie(MyString& title, int rate, double duration, int productYear, MyString& Genre, bool isBasedOnTrueEvents);

	bool getIsBasedOnTrueEvents() const;
	double getTicketPrice() const override;
	
	Movie* clone() const override {
		return new DocumentaryMovie(*this); 
	}
};