#include "DramaMovie.h"

// Конструктор за създаване на DramaMovie обект.
DramaMovie::DramaMovie(MyString& title, int rate, double duration, int productYear, MyString& Genre, MoviesType type, bool hasComedyElements)
	:Movie(title, rate, duration, productYear, Genre, type), hasComedyElements(hasComedyElements)
{
}

void DramaMovie::setHasComedyElements(bool hasComedyElements)
{
	this->hasComedyElements = hasComedyElements;
}

bool DramaMovie::getHasComedyElements() const
{
	return hasComedyElements;
}

// Изчислява цената на билета за драматичен филм.
double DramaMovie::getTicketPrice() const 
{
	return basePrice + (hasComedyElements ? 2.0 : 0.0);
}

// Клонира текущия обект.
Movie* DramaMovie::clone() const
{
	
	return new DramaMovie(*this);
	
}

// Принтира информация за филма в конзолата.
void DramaMovie::print()
{
	cout << "Type Movie(1-Action movie; 2-Documentary movie; 3- Drama movie);" << endl;
	cout << "Id: " << this->getId() << "\n"
		<<"Name: " << this->getTitle().c_str() << "\n"
		<< "Type Movie: " << static_cast<int>(this->getMovieType()) << "\n"
		<< "Rate: " << this->getRate() << "\n"
		<< "Duration: " << this->getDuration() << "\n"
		<< "Production Year: " << this->getProductionYear() << "\n"
		<< "Genre: " << this->getGenre().c_str() << "\n"
		<< "Action Intensity scene: " << this->getHasComedyElements() << "\n";
}

