// CinemaManager.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <crtdbg.h>
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

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//...
	//someLogic("crit1.txt", "crit2.txt", "res.txt"); The function has no memory leak
	int* a = new int(3);

	SystemManager system;
	
	system.loadHallsFromFiles();
	system.loadMoviesFromFile();
	system.loadSessionFromFile();
	system.loadTicketsFromFiles();
	system.loadUsersFromFiles();
	system.saveSessionToFile();
	/*system.saveMoviesToFile();*/
	/*system.saveTicketsToFiles();*/
	
	

	User* loggedUser = nullptr;
	MyString name;
	MyString password;
	
	MyString cmd;
	bool isRunningProgram = true;
	do {
		cout << "\n> ";
		cin >> cmd;
		if (cmd.equals("exit")) {
			break;
		}
		else if (cmd.equals("login")) {
			MyString name, password;
			cout << "Enter name:";
			cin >> name;
			cout << "Enter password:";
			cin>> password;

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

			if (system.registerUser(name, password)) {
				cout << "Registration successful!\n";
			}
			else {
				cout << "User already exists.\n";
			}
		}
		else if (loggedUser != nullptr) {
			if (loggedUser->getId() == 1) {
				if (cmd.equals("add-movie")) {
					MyString title,genre;
					int rate, typeMovie, productionYear;
					double duration;
					cout << "Enter type movie(1-Action movie; 2-Documentary movie; 3-Drama movie):";
					cin >> typeMovie;
					
					
					cout << "Enter title";
					cin.ignore();
					getline(cin, title, '\n');
					cout << "Enter rate";
					cin >> rate;
					cout << "Enter duration";
					cin >> duration;
					cout << "Enter production year";
					cin >> productionYear;
					cout << "Enter genre";
					cin.ignore();
					getline(cin, genre, '\n');

					cout << "Movie size:" << system.getMovies().getSize();
					MoviesType movieType = static_cast<MoviesType>(typeMovie);
					Admin* admin = static_cast<Admin*>(loggedUser);
					switch (movieType) {
						case MoviesType::ActionMovie: {


							int actionIntensity;
							cout << "Enter action intensity:";
							cin >> actionIntensity;

							ActionMovie* action = new ActionMovie(title, rate, duration, productionYear, genre, movieType, actionIntensity);
							admin->addActionMovie(system, action);
							delete action;
							break;
						}
						case MoviesType::DocumentaryMovie: {


							bool isBasedOnTrueEvents;
							cout << "Enter based on true events (0 or 1): ";
							cin >> isBasedOnTrueEvents;
							DocumentaryMovie* documentary = new DocumentaryMovie(title, rate, duration, productionYear, genre, movieType, isBasedOnTrueEvents);
							admin->addDocumentaryMovie(system, documentary);
							delete documentary;
							break;
						}
						case MoviesType::DramaMovie: {


							bool hasComedyElements;
							cout << "Enter based on true events (0 or 1): ";
							cin >> hasComedyElements;
							DramaMovie* drama = new DramaMovie(title, rate, duration, productionYear, genre, movieType, hasComedyElements);
							admin->addDramaMovie(system, drama);
							delete drama;
							break;
						}
						default: {
							cout << "Unknown movie type: " << typeMovie << endl;
						}
						
					}
					cout << "Movie size:" << system.getMovies().getSize();
					
				}
			}


			if (cmd.equals("buy-ticket")) {
				int sessionId, row, col;
				system.printAllSessions();
				cout << "Enter session id:";
				cin >> sessionId;
				cout << "Enter row:";
				cin >> row;
				cout << "Enter column:";
				cin >> col;

				Session* session = system.findSessionById(sessionId);
				
				if (session == nullptr) {
					cout << "Not found session with such Id" << endl;

				}
				else {
					try {
						session->reserveSeat(row,col);
						Ticket tick(session);

						Movie* movie = session->getMovie();

						switch (movie->getMovieType()) {
						case MoviesType::ActionMovie: {
							ActionMovie* action = dynamic_cast<ActionMovie*>(movie);
							if (loggedUser->getBalance() < action->getTicketPrice()) {
								throw exception("Cant't buy ticket");
							}
							else {
								int userBalance = loggedUser->getBalance();
								cout << "UserBalance=" << userBalance<<endl;
								loggedUser->setBalance(userBalance - action->getTicketPrice());
								cout << "Price=" << action->getTicketPrice() << endl;
								cout << "UserBalance=" << loggedUser->getBalance()<<endl;
							}
							break;
						}
						case MoviesType::DocumentaryMovie: {
							DocumentaryMovie* documentary = dynamic_cast<DocumentaryMovie*>(movie);
							if (loggedUser->getBalance() < documentary->getTicketPrice()) {
								throw exception("Cant't buy ticket");
							}
							else {

							}
							break;
						}
						case MoviesType::DramaMovie: {
							DramaMovie* drama = dynamic_cast<DramaMovie*>(movie);
							if (loggedUser->getBalance() < drama->getTicketPrice()) {
								throw exception("Cant't buy ticket");
							}
							else {

							}
							break;
						}
						default:
							cout << "Unknown movie type: " << static_cast<int>(movie->getMovieType()) << endl;
						}
						cout << "ticketSize:" << system.getAllTickets().getSize()<<endl;
						loggedUser->addTicket(tick);
						system.addTicket(tick);
						cout << "ticketSize:" << system.getAllTickets().getSize() << endl;
						session->displaySeats();
					}
					catch (const std::ios_base::failure& e) {
						std::cerr << "File read error: " << e.what() << std::endl;
					}
				}


			}
			else if (cmd.equals("list-history")) {
				system.printWatchedMovies(loggedUser);
			}
			else if (cmd.equals("list-movies")) {
				system.printAllMoviesFromSessions();
			}
		}
	}while (isRunningProgram);
	
		

	system.saveUsersToFiles();

}
