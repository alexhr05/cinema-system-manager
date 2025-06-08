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

public:
	SystemManager();
	~SystemManager();

	void loadHallsFromFiles();
	void saveHallsToFiles();

	void loadUsersFromFiles();
	void saveUsersToFiles();

	void loadTicketsForUser();
	void saveTicketsForUser(User* user);

	void loadMoviesFromFile();    
	void saveMoviesToFile();      

	bool registerUser(MyString name, MyString password);
	User* login(MyString name, MyString password);
	void logout();

	void addMovie(Movie* movie);
	void addHall(Hall* hall);
	

	MyVector<User*> getUsers() const;
	MyVector<Movie*> getMovies() const;
	MyVector<Hall*> getHalls() const;

	void addDefaultAdmin();

	Hall* findHallById(int id);
	void printHalls();

};