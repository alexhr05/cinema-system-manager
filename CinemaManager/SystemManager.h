#pragma once
#include "User.h"
#include "Movie.h"
#include "Hall.h"
#include "Ticket.h"
#include "MyVector.hpp"
#include "MyString.h"

class User;
class Movie;
class Hall;
class Ticket;


class SystemManager {
private:
	MyVector<User*> users;
	MyVector<Movie*> movies;
	MyVector<Hall*> halls;
	MyVector<Ticket> allTickets;

public:
	SystemManager();
	~SystemManager();

	void loadHallsFromFiles();
	void saveHallsToFiles();

	void loadTicketsFromFiles();
	void saveTicketsToFiles();

	void loadUsersFromFiles();
	void saveUsersToFiles();

	void loadMoviesFromFile();    
	void saveMoviesToFile();   

	void saveToFile() const;
	void loadFromFile();

	bool registerUser(MyString name, MyString password);
	User* login(MyString name, MyString password);
	void logout();

	void addMovie(Movie* movie);
	void addHall(Hall* hall);
	

	MyVector<User*> getUsers() const;
	MyVector<Movie*> getMovies() const;
	MyVector<Hall*> getHalls() const;
	MyVector<Ticket> getAllTickets() const;

	Ticket& findTicketById(int id);
	Movie* findMovieById(int id);
	void addDefaultAdmin();

	Hall* findHallById(int id);
	void printHalls();

	tm createTimeStruct(int year, int month, int day, int hour);
	void removeMovieSystem(Movie* movie);
	void removeHallSystem(Hall* hall);
};