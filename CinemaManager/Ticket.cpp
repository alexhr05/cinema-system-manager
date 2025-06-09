#include "Ticket.h"
#include "Hall.h"
#include "Movie.h"
#include <iostream>
#include <ctime>

using namespace std;

Ticket::Ticket(Movie* movie, int row, int col)
	:id(++counterId), movie(movie), row(row), col(col)
{
	tm time = {};
	issueDate = time;
	
	
}
int Ticket::counterId = 0;


Ticket::Ticket(const Ticket& other) {
	this->id = other.id;
	this->row = other.row;
	this->col = other.col;
	this->issueDate = other.issueDate;
	if (other.movie != nullptr) {
		try {
			this->movie = other.movie->clone();
		}//Хваща всички изключения
		catch (...) {
			std::cerr << "Error: clone() failed, setting movie to nullptr\n";
			this->movie = nullptr;
		}
	}
	else {
		this->movie = nullptr;
	}
}

Ticket& Ticket::operator=(const Ticket& other) {
	if (this != &other) {
		this->id = other.id;
		this->row = other.row;
		this->col = other.col;
		this->issueDate = other.issueDate;
		this->movie = other.movie ? other.movie->clone() : nullptr;
	}
	return *this;
}

void Ticket::setIssuedDate(tm issuedDate)
{
	this->issueDate = issuedDate;
}

Movie* Ticket::getMovie() const
{
	return movie;
}

int Ticket::getId() const {
	return id;
}

int Ticket::getRow() const {
	return row;
}

int Ticket::getCol() const {
	return col;
}

tm Ticket::getIssueDate() const
{
	return issueDate;
}

bool Ticket::isExpired() const
{
	time_t now;
	time(&now);

	tm now_tm;

	localtime_s(&now_tm, &now);



	if (issueDate.tm_year < now_tm.tm_year)
		return true;
	if (issueDate.tm_year == now_tm.tm_year && issueDate.tm_mon < now_tm.tm_mon)
		return true;
	if (issueDate.tm_year == now_tm.tm_year &&
		issueDate.tm_mon == now_tm.tm_mon &&
		issueDate.tm_mday < now_tm.tm_mday)
		return true;


	return false;
}

void Ticket::print() const
{
	cout << "Ticket information:" << endl;

	cout << "Movie: " << movie->getTitle().c_str()
		<< " | Зала ID: " << movie->getHallId()
		<< " | Място: Ред " << row << ", Колона " << col << std::endl;

}
