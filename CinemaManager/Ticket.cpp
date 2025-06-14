#include "Ticket.h"
#include <ctime>

using namespace std;

class Session;

Ticket::Ticket(Session* session, int row, int col)
	:id(++counterId), session(session), row(row), col(col)
{

}
int Ticket::counterId = 0;


Ticket::Ticket(const Ticket& other) {
	this->id = other.id;
	this->row = other.row;
	this->col = other.col;
	this->session = other.session;
}

Ticket& Ticket::operator=(const Ticket& other) {
	if (this != &other) {
		this->id = other.id;
		this->row = other.row;
		this->col = other.col;
		this->session = other.session;
	}
	return *this;
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

Session* Ticket::getSession() const
{
	return session;
}

void Ticket::print() const
{
	cout << "Ticket info:" << endl;
	cout << "Ticket id:" << id<<endl
		<<"Row:"<<row<<endl
		<<"Column:" << col << endl
		<<"Session info:"<<endl<<endl;
	session->print();
}

bool Ticket::operator==(const Ticket& other)
{
	return this->getId() == other.getId();
}