#include "DocumantaryMovie.h"


// Конструктор на DocumentaryMovie
DocumentaryMovie::DocumentaryMovie(MyString title, int rate, double duration, int productYear, MyString Genre, MoviesType type, bool isBasedOnTrueEvents)
	:Movie(title, rate, duration, productYear, Genre, type), isBasedOnTrueEvents(isBasedOnTrueEvents)
{
}

void DocumentaryMovie::setIsBasedOnTrueEvents(bool isBasedOnTrueEvents)
{
	this->isBasedOnTrueEvents = isBasedOnTrueEvents;
}

bool DocumentaryMovie::getIsBasedOnTrueEvents() const
{
	return isBasedOnTrueEvents;
}

// Изчислява цената на билета.
double DocumentaryMovie::getTicketPrice() const {
	return basePrice + (isBasedOnTrueEvents ? 3.0 : 0.0);
}

// Клонира обекта (създава динамично копие от текущия филм).
Movie* DocumentaryMovie::clone() const
{
	
	return new DocumentaryMovie(*this);
	
}

// Принтира информация за филма в конзолата.
void DocumentaryMovie::print()
{
	cout << "Type Movie(1-Action movie; 2-Documentary movie; 3- Drama movie);" << endl;
	cout << "Id: " << this->getId() << "\n"
		<<"Name: " << this->getTitle().c_str() << "\n"
		<< "Type Movie: " << static_cast<int>(this->getMovieType()) << "\n"
		<< "Rate: " << this->getRate() << "\n"
		<< "Duration: " << this->getDuration() << "\n"
		<< "Production Year: " << this->getProductionYear() << "\n"
		<< "Genre: " << this->getGenre().c_str() << "\n"
		<< "Action Intensity scene: " << this->getIsBasedOnTrueEvents() << "\n";
}
