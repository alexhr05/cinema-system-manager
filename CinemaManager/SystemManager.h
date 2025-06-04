#pragma once
#include "User.h"
#include "Movie.h"
#include "Hall.h"
#include "Ticket.h"
#include "MyVector.hpp"
#include "MyString.h"



class SystemManager {
private:
	MyVector<User> users;
	MyVector<Movie> movies;
	MyVector<Hall> halls;
public:
	SystemManager();
	void loadHallsFromFiles();
	void saveHallsToFiles();

	void loadUsersFromFiles();
	void saveUsersToFiles();

	void loadMoviesFromFiles();    
	void saveMoviesToFiles();      

	void login(MyString& name, MyString& password);
	void logout();

	void addMovie(Movie& movie);
	void addHall(const Hall& hall);

	MyVector<User> getUsers() const;
	MyVector<Movie> getMovies() const;
	MyVector<Hall> getHalls() const;

	void printHalls();

};