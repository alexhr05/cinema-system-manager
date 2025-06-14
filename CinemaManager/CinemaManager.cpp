// CinemaManager.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "User.h"
#include "Admin.h"
#include "Hall.h"
#include "Movie.h"
#include "DocumantaryMovie.h"
#include "DramaMovie.h"
#include "ActionMovie.h"
#include "Session.h"
#include "MyString.h"
#include "MyVector.hpp"
#include "SystemManager.h"


using namespace std;

int main()
{
	SystemManager system;
	
	system.loadHallsFromFiles();
	system.loadMoviesFromFile();
	system.loadSessionFromFile();
	system.loadTicketsFromFiles();
	system.loadUsersFromFiles();
	
	/*system.saveMoviesToFile();*/
	/*system.saveTicketsToFiles();*/
	
	cout << "MMAINN TicketSize=" << system.getAllTickets().getSize()<<endl;

	User* loggedUser = nullptr;
	Admin* admin = nullptr;
	MyString name;
	MyString password;
	
	MyString cmd;
	bool isRunningProgram = true;
	do {
		cout << "\n> ";
		cin >> cmd;
		if (cmd.equals("exit")) {
			cout << "EXIT TicketSize=" << system.getAllTickets().getSize() << endl;
			break;
		}
		else if (cmd.equals("login")) {
			MyString name, password;
			cout << "Enter name:";
			cin.ignore();
			getline(cin, name, '\n');
			cout << "Enter password:";

			getline(cin, password, '\n');
			
			loggedUser = system.login(name, password);
			if (loggedUser == nullptr) {
				cout << "Not found such User" << endl;
			}
			else {
				cout << "Login successfully" << endl;
				
			}


		}
		else if (cmd.equals("register")) {
			MyString name, password;
			cout << "Enter name:";
			cin >> name;
			cout << "Enter password:";
			cin>> password;
			double balance;
			cout << "Enter balance:";
			cin >> balance;
			if (balance >= 0) {
				if (system.registerUser(name, password, balance)) {
					cout << "Registration successful!\n";
				}
				else {
					cout << "User already exists.\n";
				}
			}
			else {
				cout << "Invalid data."<<endl;
			}
			
		}
		else if (cmd.equals("logout")) {
			loggedUser = nullptr;
			cout << "Logout successfully!"<<endl;
			continue;
		}
		else if (cmd.equals("commands-user")) {
			cout << "Commands for User:" << endl;
			MyString userCommands = "1. buy-tciket\n2. list-history\n3. list-movies\n";
			cout << userCommands.c_str();
		}
		else if (cmd.equals("commands-admin")) {
			cout << "Commands for Admin:" << endl;
			MyString allCommands = "1. add-user\n2. add-movie\n3. create-session\n4. open-haul\n5. close-haul\n6. remove-movie\n7. update-movie-title\n8. list-user-history\n9. list-user-tickets\n10. list-users\n11. remove-user\n";
			cout << allCommands.c_str();
		}
		
		if (loggedUser != nullptr) {
			loggedUser->handleCommand(system, cmd);
		}
		else {
			cout << "If you want to continue with another action login to system " << endl;
		}

	}while (isRunningProgram);
	

	system.saveHallsToFiles();
	system.saveMoviesToFile();
	system.saveTicketsToFiles();
	system.saveSessionToFile();
	system.saveUsersToFiles();

}
