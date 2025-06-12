#pragma once
#include "SystemManager.h"
#include "Ticket.h"
#include "Movie.h"
#include "MyVector.hpp"
#include "Mystring.h"

class Ticket;
class Movie;
class SystemManager;

class User {
private:
	static int counterId;
	int id;
	MyString name;
	MyString password;
	double balance;

	MyVector<Ticket> tickets;
	MyVector<Movie*> watchedMovies;

public:
	User();
	User(MyString name,MyString password,double balance);
	User(MyString name, MyString password);
	
	

	void setName(MyString& name);
	void setPassword(MyString& password);
	void setBalance(double balance);

	MyString getName() const;
	MyString getPassword() const;
	double getBalance() const;
	int getId() const;
	MyVector<Ticket> getTickets() const;
	MyVector<Movie*> getWatchedMovies() const;
	void addTicket(Ticket& ticket);
	void addWatchedMovies(Movie* movie);

	void checkExpiredTickets();
	void setId(int newId);


	void handleCommand(MyString command, SystemManager& system);
};