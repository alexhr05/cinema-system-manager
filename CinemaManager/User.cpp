#include "User.h"
#include "Mystring.h"


User::User() : id(++counterId),name(""), password(""), balance(0) {}

User::User(MyString& name, MyString& password, double balance) : id(++counterId), name(name), password(password), balance(balance) {

}

void User::setId(int newId) {
	this->id = newId;
}

void User::setName(MyString& name) {
	this->name = name;
}

void User::setPassword(MyString& password) {
	this->password = password;
}

void User::setBalance(double balance) {
	this->balance = balance;
}

MyString User::getName() const {
	return name;
}

MyString User::getPassword() const {
	return password;
}

double User::getBalance() const {
	return balance;
}

int User::counterId = 0;

int User::getId() const {
	return id;
}

MyVector<Ticket> User::getTickets() const
{
	return tickets;
}

MyVector<Movie*> User::getWatchedMovies() const
{
	return watchedMovies;
}

void User::checkExpiredTickets()
{
	MyVector<Ticket> updatedTickets;

	for (int i = 0; i < tickets.getSize();i++) {
		Ticket ticket = tickets[i];
		if (ticket.isExpired()) {
			watchedMovies.add(ticket.getMovie());
		}
		else {
			updatedTickets.add(ticket);
		}
	}

	tickets = updatedTickets;
}
