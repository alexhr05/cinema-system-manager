#include "User.h"
//#include "Ticket.h"
#include "Mystring.h"
#include "MyVector.hpp"


User::User() : id(++counterId),name(""), password(""), balance(0), tickets(MyVector<Ticket>()), watchedMovies(MyVector<Movie*>()) {}

User::User(MyString name, MyString password) : id(++counterId), name(name), password(password), balance(0), tickets(MyVector<Ticket>()), watchedMovies(MyVector<Movie*>())
{

}


User::User(MyString name, MyString password, double balance) : id(++counterId), name(name), password(password), balance(balance), tickets(MyVector<Ticket>()), watchedMovies(MyVector<Movie*>()) {

}

void User::setId(int newId) {
	this->id = newId;

	if (newId >=counterId) {
		counterId = newId + 1;
	}
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

void User::setTickets(MyVector<Ticket> tickets)
{
	this->tickets = tickets;
}

void User::setWatchedMovies(MyVector<Movie*> watchedMovies)
{
	this->watchedMovies = watchedMovies;
}

void User::addTicket(Ticket& ticket)
{
	tickets.add(ticket);
}

void User::addWatchedMovies(Movie* movie)
{
	watchedMovies.add(movie);
}

void User::checkExpiredTickets()
{
	MyVector<Ticket> updatedTickets;

	for (int i = 0; i < tickets.getSize();i++) {
		Ticket ticket = tickets[i];
		if (ticket.getSession()->isExpired()) {
			watchedMovies.add(ticket.getSession()->getMovie());
		}
		else {
			updatedTickets.add(ticket);
		}
	}

	tickets = updatedTickets;
}
