#pragma once
#include "User.h"
#include "Admin.h"
#include "Movie.h"
#include "Hall.h"
#include "Ticket.h"
#include "MyVector.hpp"
#include "MyString.h"
#include "Session.h"

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
	MyVector<Session*> sessions;

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

	void saveSessionToFile();
	void loadSessionFromFile();

	bool registerUser(MyString name, MyString password);
	User* login(MyString name, MyString password);
	void logout();

	void addMovie(Movie* movie);
	void addHall(Hall* hall);
	void addTicket(Ticket ticket);

	MyVector<User*> getUsers() const;
	MyVector<Movie*> getMovies() const;
	MyVector<Hall*> getHalls() const;
	MyVector<Ticket> getAllTickets() const;
	MyVector<Session*> getSessions() const;

	Ticket findTicketById(int id);
	Movie* findMovieById(int id);
	Session* findSessionById(int id);
	User* findUserById(int id);
	void addDefaultAdmin();

	Hall* findHallById(int id);
	void printHalls();

	tm createTimeStruct(int year, int month, int day, int hour);
	void removeMovieSystem(int movieId);
	void removeHallSystem(int hallId);
	void removeUserSystem(int userId);
	void printWatchedMovies(User* user);
	void printAllMoviesFromSessions();
	void printAllSessions();
	void printAllUsers();


	
};