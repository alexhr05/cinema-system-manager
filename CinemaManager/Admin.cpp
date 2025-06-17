#include "Admin.h"
#include "Hall.h"
// Конструктор на Admin
Admin::Admin(MyString name, MyString password, double balance)
    : User(name, password, balance) {
    
}

// Обработва специфични команди за администратор като добавяне на филм, потребител, сесия и други
void Admin::handleUserSpecificCommand(SystemManager& system, MyString cmd)
{
	
	// Разпознаване на командата и извършване на съответното действие
	if(cmd.equals("add-user")) {
		// Добавя нов потребител
		MyString name;
		MyString password;
		double balance;
		
		cout << "Enter user name:";
		cin.ignore();
		getline(cin, name, '\n');
		cout << "Enter user password:";
		
		getline(cin, password, '\n');

		cout << "Enter user balance:";
		cin >> balance;
		User* newUser = new User(name, password, balance);
		addUser(system, newUser);
		
	}
	else if (cmd.equals("add-movie")) {
		// Добавя нов филм 
		MyString title, genre;
		int rate, typeMovie, productionYear;
		double duration;
		cout << "Enter type movie(1-Action movie; 2-Documentary movie; 3-Drama movie):";
		cin >> typeMovie;


		cout << "Enter title:";
		cin.ignore();
		getline(cin, title, '\n');
		cout << "Enter rate between 1 to 5 :";
		cin >> rate;
		cout << "Enter duration:";
		cin >> duration;
		cout << "Enter production year:";
		cin >> productionYear;
		cout << "Enter genre:";
		cin.ignore();
		getline(cin, genre, '\n');
		if (rate < 0 || rate >5 || duration <0 || productionYear <0 ) {
			cout<<"Invalid data for adding movie"<<endl;
		}
		else {
			MoviesType movieType = static_cast<MoviesType>(typeMovie);

			switch (movieType) {
			case MoviesType::ActionMovie: {


				int actionIntensity;
				cout << "Enter action intensity:";
				cin >> actionIntensity;

				ActionMovie* action = new ActionMovie(title, rate, duration, productionYear, genre, movieType, actionIntensity);
				addActionMovie(system, action);
				break;
			}
			case MoviesType::DocumentaryMovie: {


				bool isBasedOnTrueEvents;
				cout << "Enter based on true events (0 or 1): ";
				cin >> isBasedOnTrueEvents;
				DocumentaryMovie* documentary = new DocumentaryMovie(title, rate, duration, productionYear, genre, movieType, isBasedOnTrueEvents);
				addDocumentaryMovie(system, documentary);
				break;
			}
			case MoviesType::DramaMovie: {
				bool hasComedyElements;
				cout << "Enter based on true events (0 or 1): ";
				cin >> hasComedyElements;
				DramaMovie* drama = new DramaMovie(title, rate, duration, productionYear, genre, movieType, hasComedyElements);
				addDramaMovie(system, drama);
				break;
			}
			default: {
				cout << "Unknown movie type: " << typeMovie << endl;
			}

			}
			cout << "Successfully added movie" << endl;
		}

		
	}
	else if (cmd.equals("create-session")) {
		// Създава нова прожекционна сесия

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
			addNewSession(system, session);
			cout << "Successfully added session" << endl;
		}

	}
	else if (cmd.equals("open-haul")) {
		// Отваря нова зала

		int rows, cols;
		cout << "Enter rows for hall:";
		cin >> rows;
		cout << "Enter cols for hall:";
		cin >> cols;
		if (rows <= 0 || cols <= 0) {
			cout << "Invlaid data for rows and columns" << endl;
		}
		else {
			Hall* hall = new Hall(rows, cols);

			addHall(system, hall);
			cout << "Successfully added hall" << endl;
		}
		
	}
	else if (cmd.equals("remove-movie")) {
		// Премахва филм по ID

		int movieId;
		cout << "Enter movie id to remove:";
		cin >> movieId;
		removeMovie(system, movieId);

	}
	else if (cmd.equals("close-haul")) {
		// Затваря зала по ID

		int hallId;
		cout << "Enter hall id:";
		cin >> hallId;
		removeHall(system, hallId);
	}
	else if (cmd.equals("update-movie-title")) {
		// Актуализира заглавието на филм по ID

		int movieId;
		cout << "Enter movie id:";
		cin >> movieId;
		MyString title;
		cout << "Enter title:";
		cin.ignore();
		getline(cin, title, '\n');


		updateTitleMovie(system, movieId, title);
	}
	else if (cmd.equals("list-user-history")) {
		// Извежда гледаните филми на потребител

		int userId;
		cout << "Enter user Id:";
		cin >> userId;
		printUsersWatchedMovies(system, userId);

	}
	else if (cmd.equals("list-user-tickets")) {
		// Извежда всички билети на потребител
		

		int userId;
		cout << "Enter user Id";
		cin >> userId;
		printUsersTickets(system, userId);

	}
	else if (cmd.equals("list-users")) {
		// Извежда списък с всички потребители

		system.printAllUsers();
	}
	else if (cmd.equals("remove-user")) {
		// Премахва потребител по ID

		int userId;
		cout << "Enter user id:";
		cin >> userId;
		removeUser(system, userId);
	}
	else if (cmd.equals("list-movies-cinema")) {
		MyVector<Movie*> movies = system.getMovies();
		cout << "All movies:" << endl<<endl;
		for (size_t i = 0; i < movies.getSize(); i++)
		{
			movies[i]->print();
			cout << endl;
		}
		
	}
	else if (cmd.equals("list-halls")) {
		
		MyVector<Hall*> halls = system.getHalls();
		cout << "All movies:" << endl << endl;
		for (size_t i = 0; i < halls.getSize(); i++)
		{
			cout << "Hall Id:" << halls[i]->getId() << "\n"
				<< "Hall rows: " << halls[i]->getRows()<< "\n"
				<<"Hall columns: "<< halls[i]->getCols()<<"\n";
			cout << endl;
		}

	}

}


void Admin::addActionMovie(SystemManager& system, ActionMovie* action)
{
    system.addMovie(action);
}

void Admin::addDramaMovie(SystemManager& system, DramaMovie* drama)
{
    system.addMovie(drama);
}

void Admin::addDocumentaryMovie(SystemManager& system, DocumentaryMovie* documentary)
{
    system.addMovie(documentary);
}


void Admin::removeMovie(SystemManager& system, int movieId)
{
    system.removeMovieSystem(movieId);
}

void Admin::addHall(SystemManager& system, Hall* hall)
{
    system.addHall(hall);
}

void Admin::addNewSession(SystemManager& system, Session* session)
{
    system.addSession(session);
}

void Admin::removeHall(SystemManager& system, int hallId)
{
    system.removeHallSystem(hallId);
}

void Admin::addUser(SystemManager& system, User* user)
{
	system.addDefaultUser(user);
}

void Admin::removeUser(SystemManager& system, int userId)
{
    system.removeUserSystem(userId);
}

void Admin::updateTitleMovie(SystemManager& system, int movieId, MyString title)
{
    system.updateSystemMovieTitle(movieId, title);
}

void Admin::printUsersWatchedMovies(SystemManager& system,int userId)
{
    system.printAllUsersWatchedMovies(userId);
}

void Admin::printUsersTickets(SystemManager& system, int userId)
{
    system.printAllUsersTickets(userId);
}


