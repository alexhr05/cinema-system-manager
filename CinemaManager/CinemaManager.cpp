// CinemaManager.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "User.h"
#include "Admin.h"
#include "Hall.h"
#include "Movie.h"
#include "ActionMovie.h"
#include "MyString.h"
#include "MyVector.hpp"
#include "SystemManager.h"

using namespace std;

int main()
{
	SystemManager system;
	system.loadHallsFromFiles();
	system.loadUsersFromFiles();
	system.saveMoviesToFile();
	system.loadMoviesFromFile();
	
	
	/*Hall* h = new Hall(5, 5);
	h->reserveSeat(1,1);
	system.addHall(h);

	Hall* hall2 = new Hall(3,5);
	hall2->reserveSeat(0, 0);
	system.addHall(hall2);

	system.printHalls();*/
	/*User* loggedUser = nullptr;
	MyString name;
	MyString password;

	cout << "> ";
	MyString cmd;*/
	/*while (cin>>cmd) {
		if (cmd.equals("exit")) {
			break;
		}
		else if (cmd.equals("login")) {
			MyString name, password;
			cin >> name >> password;

			loggedUser = system.login(name, password);
			
			if (loggedUser == nullptr) {
				cout << "Not found such User" << endl;
			}
			else {
				cout << "name" << loggedUser->getName().c_str();
			}

		}
		else if (cmd.equals("register")) {
			MyString name, password;
			cin >> name >> password;

			if (system.registerUser(name, password)) {
				cout << "Registration successful!\n";
			}
			else {
				cout << "User already exists.\n";
			}
		}
		cout << "> ";
	}*/
	//time_t now = time(0);
	//tm ltm ;

	//localtime_s(&ltm, &now);
	//
	//MyVector<Ticket> tick;
	//name = "Star wars";
	//MyString Genre = "fas";
	//ActionMovie* am = new ActionMovie(name, 4, 2.5, 2000, Genre, 10);

	//Ticket ticks(am, 2, 3);
	//tick.add(ticks);
	//loggedUser = new Admin("admin", "admin123");

	//loggedUser->addTicket(ticks);
	//tick = loggedUser->getTickets();
	//
	//cout<<"tickSize="<<tick.getSize();
	//Movie* mov = tick[0].getMovie();
	/*cout<<"rows="<<mov->getHall().getRows();*/
	/*for (size_t i = 0; i < tick.getSize(); i++)
	{
		cout << "Movie: " << tick[i].getMovie()->getTitle().c_str() << "\n";
		cout << "Row: " << tick[i].getRow() << ", Col: " << tick[i].getCol() << "\n";
		cout << "Sold at: "
			<< 1900 + ltm.tm_year << "-"
			<< 1 + ltm.tm_mon << "-"
			<< ltm.tm_mday << " "
			<< ltm.tm_hour << ":"
			<< ltm.tm_min << ":"
			<< ltm.tm_sec << "\n\n";

	}*/
	
	

	
	//system.saveHallsToFiles();
	/*system.saveUsersToFiles();*/
	
	//time_t now;
	//time(&now);

	//tm now_tm;
	//tm ticket_tm;

	//localtime_s(&now_tm, &now);
	////localtime_s(&ticket_tm, &issueDate);


	//cout << now_tm.tm_year;


}
