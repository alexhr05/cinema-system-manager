#include "ActionMovie.h"
#include <iostream>

using namespace std;

// Конструктор с параметри за създаване на обект от тип ActionMovie.
ActionMovie::ActionMovie(MyString& title, int rate, double duration, int productYear, MyString& Genre, MoviesType type, int actionIntensity)
	:Movie(title, rate, duration, productYear, Genre, type), actionIntensity(actionIntensity)
{
	
}

// Копиращ конструктор за ActionMovie.
ActionMovie::ActionMovie(const ActionMovie& other) : Movie(other)
{
	this->actionIntensity = other.actionIntensity;
}

// Задава стойност на actionIntensity. Валидира дали стойността е в допустимите граници (0 до 20).
void ActionMovie::setActionIntensity(int actionIntensity)
{
	if (actionIntensity < 0 || actionIntensity > 20)
		cout << "ActionIntensity is not in the interval between 0 and 20";
		return;

	this->actionIntensity = actionIntensity;
}


int ActionMovie::getActionIntensity() const
{
	return actionIntensity;
}

// Изчислява и връща цената на билет според actionIntensity.
double ActionMovie::getTicketPrice() const
{
	return basePrice + (actionIntensity * 1.5);
}

// Клонира (копира) текущия обект и връща нова динамично заделена инстанция.
Movie* ActionMovie::clone() const
{
	
	return new ActionMovie(*this);
	
}

// Извежда информация за филма в конзолата.
void ActionMovie::print()
{
	cout << "Type Movie(1-Action movie; 2-Documentary movie; 3- Drama movie);" << endl;
	cout << "Id: " << this->getId() << "\n"
		<<"Name: " << this->getTitle().c_str() << "\n"
		<< "Type Movie: " << static_cast<int>(this->getMovieType()) << "\n"
		<< "Rate: " << this->getRate() << "\n"
		<< "Duration: " << this->getDuration() << "\n"
		<< "Production Year: " << this->getProductionYear() << "\n"
		<< "Genre: " << this->getGenre().c_str() << "\n"
		<< "Action Intensity scene: " << this->getActionIntensity() << "\n";
}