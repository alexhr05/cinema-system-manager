#include "User.h"
//#include "Ticket.h"
#include "SystemManager.h"
#include "Mystring.h"
#include "MyVector.hpp"


void User::handleUserSpecificCommand(SystemManager& system, MyString command)
{
	return;
}

User::User() : id(counterId++),name(""), password(""), balance(0), tickets(MyVector<Ticket>()), watchedMovies(MyVector<Movie*>()) {}

User::User(MyString name, MyString password) : id(++counterId), name(name), password(password), balance(0), tickets(MyVector<Ticket>()), watchedMovies(MyVector<Movie*>())
{

}


User::User(MyString name, MyString password, double balance) : id(counterId++), name(name), password(password), balance(balance), tickets(MyVector<Ticket>()), watchedMovies(MyVector<Movie*>()) {

}

void User::setId(int newId) {
	this->id = newId;

	if (newId >=counterId) {
		counterId = newId + 1;
	}
}

void User::handleCommand(SystemManager& system, MyString cmd) {
	
	try {
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

					Ticket tick(session, row, col);
					if (!session->reserveSeat(row, col)) {
						throw invalid_argument("The seat is reserved");
					}
					
					Movie* movie = session->getMovie();

					switch (movie->getMovieType()) {
					case MoviesType::ActionMovie: {
						ActionMovie* action = dynamic_cast<ActionMovie*>(movie);
						if (getBalance() < action->getTicketPrice()) {
							throw exception("Cant't buy ticket");
						}
						else {
							int userBalance = getBalance();
							cout << "UserBalance=" << userBalance << endl;
							setBalance(userBalance - action->getTicketPrice());
							cout << "Price=" << action->getTicketPrice() << endl;
							cout << "UserBalance=" << getBalance() << endl;
						}
						break;
					}
					case MoviesType::DocumentaryMovie: {
						DocumentaryMovie* documentary = dynamic_cast<DocumentaryMovie*>(movie);
						if (getBalance() < documentary->getTicketPrice()) {
							throw exception("Cant't buy ticket");
						}
						else {

						}
						break;
					}
					case MoviesType::DramaMovie: {
						DramaMovie* drama = dynamic_cast<DramaMovie*>(movie);
						if (getBalance() < drama->getTicketPrice()) {
							throw exception("Cant't buy ticket");
						}
						else {

						}
						break;
					}
					default:
						cout << "Unknown movie type: " << static_cast<int>(movie->getMovieType()) << endl;
					}
					cout << "ticketSize:" << system.getAllTickets().getSize() << endl;
					addTicket(tick);
					system.addTicket(tick);
					cout << "ticketSize:" << system.getAllTickets().getSize() << endl;
					session->displaySeats();
				}
				catch (const invalid_argument& e) {
					cout << e.what() << endl;
				}
				catch (const std::ios_base::failure& e) {
					std::cerr << "File read error: " << e.what() << std::endl;
				}
			}


		}
		else if (cmd.equals("list-history")) {
			system.printWatchedMovies(id);
		}
		else if (cmd.equals("list-movies")) {
			system.printAllMoviesFromSessions();
		}
		else {
			handleUserSpecificCommand(system, cmd);
		}
	}catch (const invalid_argument& e) {
		cout << e.what() << endl;
	}
	catch (const exception& e) {
		cout << "Something went wrong: " << e.what() << endl;
		return;
	}
	
}


void User::setName(MyString& name) {
	this->name = name;
}

void User::setPassword(MyString& password) {
	this->password = password;
}

void User::setBalance(double balance) {
	this->balance = balance;
}

MyString User::getName() const {
	return name;
}

MyString User::getPassword() const {
	return password;
}

double User::getBalance() const {
	return balance;
}

int User::counterId = 0;

int User::getId() const {
	return id;
}

MyVector<Ticket> User::getTickets() const
{
	return tickets;
}

MyVector<Movie*> User::getWatchedMovies() const
{
	return watchedMovies;
}

void User::setTickets(MyVector<Ticket> tickets)
{
	this->tickets = tickets;
}

void User::setWatchedMovies(MyVector<Movie*> watchedMovies)
{
	this->watchedMovies = watchedMovies;
}

void User::addTicket(Ticket& ticket)
{
	tickets.add(ticket);
}

void User::addWatchedMovies(Movie* movie)
{
	watchedMovies.add(movie);
}

void User::checkExpiredTickets()
{
	MyVector<Ticket> updatedTickets;

	for (int i = 0; i < tickets.getSize();i++) {
		Ticket ticket = tickets[i];
		if (ticket.getSession()->isExpired()) {
			watchedMovies.add(ticket.getSession()->getMovie());
		}
		else {
			updatedTickets.add(ticket);
		}
	}

	tickets = updatedTickets;
}
