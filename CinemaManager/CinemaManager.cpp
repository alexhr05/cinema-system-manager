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
	system.saveSessionToFile();
	/*system.saveMoviesToFile();*/
	/*system.saveTicketsToFiles();*/
	
	

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

			if (system.registerUser(name, password)) {
				cout << "Registration successful!\n";
			}
			else {
				cout << "User already exists.\n";
			}
		}
		if (loggedUser != nullptr) {
			
			if (loggedUser->getId() == 1) {
				admin = new Admin(loggedUser->getName(), loggedUser->getPassword(), loggedUser->getBalance());
				admin->setId(1);
			}
			if (admin != nullptr) {

				cout << "minava prez admin" << endl;

				if (cmd.equals("add-movie")) {
					MyString title, genre;
					int rate, typeMovie, productionYear;
					double duration;
					cout << "Enter type movie(1-Action movie; 2-Documentary movie; 3-Drama movie):";
					cin >> typeMovie;


					cout << "Enter title:";
					cin.ignore();
					getline(cin, title, '\n');
					cout << "Enter rate:";
					cin >> rate;
					cout << "Enter duration:";
					cin >> duration;
					cout << "Enter production year:";
					cin >> productionYear;
					cout << "Enter genre:";
					cin.ignore();
					getline(cin, genre, '\n');

					MoviesType movieType = static_cast<MoviesType>(typeMovie);

					switch (movieType) {
					case MoviesType::ActionMovie: {


						int actionIntensity;
						cout << "Enter action intensity:";
						cin >> actionIntensity;

						ActionMovie* action = new ActionMovie(title, rate, duration, productionYear, genre, movieType, actionIntensity);
						admin->addActionMovie(system, action);
						break;
					}
					case MoviesType::DocumentaryMovie: {


						bool isBasedOnTrueEvents;
						cout << "Enter based on true events (0 or 1): ";
						cin >> isBasedOnTrueEvents;
						DocumentaryMovie* documentary = new DocumentaryMovie(title, rate, duration, productionYear, genre, movieType, isBasedOnTrueEvents);
						admin->addDocumentaryMovie(system, documentary);
						break;
					}
					case MoviesType::DramaMovie: {
						bool hasComedyElements;
						cout << "Enter based on true events (0 or 1): ";
						cin >> hasComedyElements;
						DramaMovie* drama = new DramaMovie(title, rate, duration, productionYear, genre, movieType, hasComedyElements);
						admin->addDramaMovie(system, drama);
						break;
					}
					default: {
						cout << "Unknown movie type: " << typeMovie << endl;
					}

					}
				}
				else if (cmd.equals("create-session")) {
					int movieId, hallId;

					cout << "Enter movie id:";
					cin >> movieId;
					Movie* movie = system.findMovieById(movieId);
					cout << "Enter hall id:";
					cin >> hallId;
					Hall* hall = system.findHallById(hallId);
					tm startTime = {};
					int year, month, day, hour;
					int zero = 0;
					int allMonths = 12;
					int maxDays = 31;
					int maxHour = 24;
					cout << "Enter year:";
					cin >> year;
					cout << "Enter month:";
					cin >> month;
					cout << "Enter day:";
					cin >> day;
					cout << "Enter hour:";
					cin >> hour;
					if (year <= zero || month < zero || month > allMonths || day < zero || day > maxDays || hour < zero || hour > maxHour) {
						cout << "One of the fields is not in the right range for year, month, day or hour" << endl;
					}
					else {
						startTime = system.createTimeStruct(year, month, day, hour);
						cout << startTime.tm_year << " " << startTime.tm_mon << " " << startTime.tm_wday << " " << startTime.tm_hour << endl;
						Session* session = new Session(movie, hall, startTime);
						admin->addNewSession(system, session);
					}

				}
				else if (cmd.equals("open-haul")) {
					int rows, cols;
					cout << "Enter rows for hall:";
					cin >> rows;
					cout << "Enter cols for hall:";
					cin >> cols;

					Hall* hall = new Hall(rows, cols);

					admin->addHall(system, hall);
				}
				else if (cmd.equals("remove-movie")) {
					int movieId;
					cout << "Enter movie id to remove:";
					cin >> movieId;
					cout << "mmoiveId=" << movieId;
					admin->removeMovie(system, movieId);

				}
				else if (cmd.equals("close-haul")) {
					int hallId;
					cout << "Enter hall id:";
					cin >> hallId;
					admin->removeHall(system, hallId);
				}
				else if (cmd.equals("update-movie-title")) {
					int movieId;
					cout << "Enter movie id:";
					cin >> movieId;
					MyString title;
					cout << "Enter title:";
					cin.ignore();
					getline(cin, title, '\n');


					admin->updateTitleMovie(system, movieId, title);
				}
				else if (cmd.equals("list-user-history")) {
					int userId;
					cout << "Enter user Id";
					cin >> userId;
					admin->printUsersWatchedMovies(system, userId);

				}
				else if (cmd.equals("list-user-tickets")) {
					int userId;
					cout << "Enter user Id";
					cin >> userId;
					admin->printUsersTickets(system, userId);

				}
				else if (cmd.equals("list-users")) {

					system.printAllUsers();
				}
				else if (cmd.equals("remove-user")) {
					int userId;
					cout << "Enter user id:";
					cin >> userId;
					admin->removeUser(system, userId);
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
						/*session->reserveSeat(row,col);*/
						Ticket tick(session,row,col);

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
