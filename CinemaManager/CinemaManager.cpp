// CinemaManager.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "User.h"
#include "Hall.h"
#include "Movie.h"
#include "MyString.h"
#include "MyVector.hpp"
#include "SystemManager.h"

using namespace std;

int main()
{
	SystemManager system;
	system.loadHallsFromFiles();
	system.loadUsersFromFiles();
	
	/*Hall* h = new Hall(5, 5);
	h->reserveSeat(1,1);
	system.addHall(h);

	Hall* hall2 = new Hall(3,5);
	hall2->reserveSeat(0, 0);
	system.addHall(hall2);

	system.printHalls();*/
	User* loggedUser = nullptr;
	MyString name;
	MyString password;

	cin >> name >> password;

	loggedUser = system.login(name, password);
	if (loggedUser == nullptr) {
		cout << "Ne sushtesvuva" << endl;
	}
	else {
		cout << "name" << loggedUser->getName().c_str();
	}
	
	//system.saveHallsToFiles();
	system.saveUsersToFiles();
	
	//time_t now;
	//time(&now);

	//tm now_tm;
	//tm ticket_tm;

	//localtime_s(&now_tm, &now);
	////localtime_s(&ticket_tm, &issueDate);


	//cout << now_tm.tm_year;


}
