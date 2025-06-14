#include "Session.h"

int Session::sessionCounter = 0;

Session::Session()
    : sessionId(0), movie(nullptr), hall(nullptr) {
    time_t now = time(0);
    localtime_s(&startTime, &now);
    seats = nullptr;
}

Session::Session(Movie* movie, Hall* hall, tm& startTime)
    : sessionId(++sessionCounter), movie(movie), hall(hall), startTime(startTime) {
    allocateSeats();
}

Session::Session(const Session& other)
    : sessionId(other.sessionId), movie(other.movie), hall(other.hall), startTime(other.startTime) {
    allocateSeats();
    copySeatsFrom(other);
}

Session& Session::operator=(const Session& other) {
    if (this != &other) {
        freeSeats();
        if (other.movie != nullptr) {
    	    try {
    		    this->movie = other.movie->clone();
    	    }//Хваща всички изключения
    	    catch (...) {
    		    std::cerr << "Error: clone() failed, setting movie to nullptr\n";
    		    this->movie = nullptr;
    	    }
        }
        else {
    	    this->movie = nullptr;
        }
        hall = other.hall;
        startTime = other.startTime;
        sessionId = other.sessionId;
        allocateSeats();
        copySeatsFrom(other);
    }
    return *this;
}

Session::~Session() {
    freeSeats();
}

void Session::setId(int id)
{
    sessionId = id;
    if (id >= sessionCounter) {
        sessionCounter = id + 1;
    }
}

void Session::setNewId()
{
    sessionId = sessionCounter++;
}


void Session::allocateSeats() {
    if (!hall) return;
    int rows = hall->getRows();
    int cols = hall->getCols();

    seats = new char* [rows];
    for (int i = 0; i < rows; i++) {
        seats[i] = new char[cols];
        for (int j = 0; j < cols; j++) {
            seats[i][j] = 'F';
        }
    }
}

void Session::freeSeats() {
    if (!seats || !hall) return;
    for (int i = 0; i < hall->getRows(); i++) {
        delete[] seats[i];
    }
    delete[] seats;
    seats = nullptr;
}

void Session::copySeatsFrom(const Session& other) {
    if (!hall) return;
    for (int i = 0; i < hall->getRows(); i++)
        for (int j = 0; j < hall->getCols(); j++)
            seats[i][j] = other.seats[i][j];
}

int Session::getId() const {
    return sessionId;
}

const tm& Session::getStartTime() const {
    return startTime;
}

Hall* Session::getHall() const
{
    return hall;
}

Movie* Session::getMovie() const
{
    return movie;
}

char** Session::getSeats()
{
    return seats;
}

bool Session::reserveSeat(int row, int col) {
    if (!hall || row >= hall->getRows() || col >= hall->getCols()) return false;
    if (seats[row][col] == 'F') {
        seats[row][col] = 'R'; 
        return true;
    }
    return false;
}

bool Session::isSeatTaken(int row, int col) const {
    if (!hall || row >= hall->getRows() || col >= hall->getCols()) return false;
    return seats[row][col] == 'R';
}

void Session::displaySeats() const {
    if (!hall) return;
    for (int i = 0; i < hall->getRows(); i++) {
        for (int j = 0; j < hall->getCols(); j++) {
            cout << seats[i][j] << ' ';
        }
        cout << endl;
    }
    
}

bool Session::isExpired() const
{
    time_t now;
    time(&now);

    tm now_tm;

    localtime_s(&now_tm, &now);
    if (startTime.tm_year < now_tm.tm_year)
        return true;
    if (startTime.tm_year == now_tm.tm_year && startTime.tm_mon < now_tm.tm_mon)
        return true;
    if (startTime.tm_year == now_tm.tm_year &&
        startTime.tm_mon == now_tm.tm_mon &&
        startTime.tm_mday < now_tm.tm_mday)
        return true;


    return false;
}

void Session::print() const
{
    cout << "Session: " << sessionId << endl
        << "Movie name: " << movie->getTitle().c_str() << endl
        << " Hall id: " << hall->getId() << endl
        << "Star time: " << startTime.tm_hour << "h.   " << startTime.tm_year << "/" << startTime.tm_mon << "/" << startTime.tm_wday<<endl;
    displaySeats();
}

char Session::getSeat(int r, int c) const
{
    return seats[r][c];
}

bool Session::cancelReservation(int row, int col) {
    if (row < 0 || row >= hall->getRows() || col < 0 || col >= hall->getCols()) return false;
    if (seats[row][col] == 'R') {
        seats[row][col] = 'F';
        return true;
    }

    return false;
}

void Session::setHall(Hall* h = nullptr)
{
    this->hall = h;
}


bool Session::operator==(const Session& other)
{
    return this->getId() == other.getId();
}
