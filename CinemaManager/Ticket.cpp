#include "Ticket.h"
#include <ctime>

using namespace std;

class Session;

//Конструктор на класа Ticket
Ticket::Ticket(Session* session, int row, int col)
	:id(++counterId), session(session), row(row), col(col)
{

}
int Ticket::counterId = 0;

//Copy конструктор на класа Ticket
Ticket::Ticket(const Ticket& other) {
	this->id = other.id;
	this->row = other.row;
	this->col = other.col;
	this->session = other.session;
}

//Оператор за присвояване
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

//Метод за отпечатване на информацията за билета
void Ticket::print() const
{
	cout << "Ticket info:" << endl;
	cout << "Ticket id:" << id<<endl
		<<"Row:"<<row<<endl
		<<"Column:" << col << endl
		<<"Session info:"<<endl<<endl;
	session->print();
}

//Оператор за сравнение на равенство между билети
bool Ticket::operator==(const Ticket& other)
{
	return this->getId() == other.getId();
}