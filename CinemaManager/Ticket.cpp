#include "Ticket.h"
//#include "Hall.h"
//#include "Movie.h"
//#include "Session.h"
#include <ctime>

using namespace std;

class Session;

Ticket::Ticket(Session* session)
	:id(++counterId), session(session)
{
	
}
int Ticket::counterId = 0;


Ticket::Ticket(const Ticket& other) {
	this->id = other.id;
	this->session = other.session;
}

Ticket& Ticket::operator=(const Ticket& other) {
	if (this != &other) {
		this->id = other.id;
		this->session = other.session;
		
	}
	return *this;
}

int Ticket::getId() const {
	return id;
}

Session* Ticket::getSession() const
{
	return session;
}

bool Ticket::operator==(const Ticket& other)
{
	return this->getId() == other.getId();
}