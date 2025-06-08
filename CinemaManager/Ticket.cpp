#include "Ticket.h"
#include "Hall.h"
#include "Movie.h"
#include <iostream>
#include <ctime>

using namespace std;

Ticket::Ticket(Movie* movie, int row, int col)
	: movie(movie), row(row), col(col)
{
	
	time(&issueDate);
	
}

//Ticket::~Ticket() {
//	if (movie != nullptr) {
//		delete movie;
//	}
//	
//}


Ticket::Ticket(const Ticket& other) {
	this->row = other.row;
	this->col = other.col;
	this->issueDate = other.issueDate;
	this->movie = other.movie ? other.movie->clone() : nullptr;
}

Ticket& Ticket::operator=(const Ticket& other) {
	if (this != &other) {

		this->row = other.row;
		this->col = other.col;
		this->issueDate = other.issueDate;
		this->movie = other.movie ? other.movie->clone() : nullptr;
	}
	return *this;
}

Movie* Ticket::getMovie()
{
	return movie;
}

int Ticket::getRow() const {
	return row;
}

int Ticket::getCol() const {
	return col;
}

time_t Ticket::getIssueDate() const
{
	return issueDate;
}

bool Ticket::isExpired() const
{
	time_t now;
	time(&now);

	tm now_tm;
	tm ticket_tm;

	localtime_s(&now_tm, &now);
	localtime_s(&ticket_tm, &issueDate);


	if (ticket_tm.tm_year < now_tm.tm_year)
		return true;
	if (ticket_tm.tm_year == now_tm.tm_year && ticket_tm.tm_mon < now_tm.tm_mon)
		return true;
	if (ticket_tm.tm_year == now_tm.tm_year &&
		ticket_tm.tm_mon == now_tm.tm_mon &&
		ticket_tm.tm_mday < now_tm.tm_mday)
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
