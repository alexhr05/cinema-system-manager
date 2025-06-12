#pragma once

#include "Movie.h"

class DocumentaryMovie : public Movie {
private:
	bool isBasedOnTrueEvents;
	const double basePrice = 5.0;
public:
	//DocumentaryMovie(MyString title, int rate, double duration, int productYear, MyString Genre, int hallId, MyVector<tm>, int startHour, int endHour, MoviesType type, bool isBasedOnTrueEvents);
	DocumentaryMovie(MyString title, int rate, double duration, int productYear, MyString Genre, MoviesType type, bool isBasedOnTrueEvents);
	

	void setIsBasedOnTrueEvents(bool isBasedOnTrueEvents);

	bool getIsBasedOnTrueEvents() const;
	double getTicketPrice() const override;
	
	Movie* clone() const override;
};