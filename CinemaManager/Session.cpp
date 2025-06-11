#include "Session.h"
#include <iostream>
#include <iomanip>

int Session::sessionCounter = 1;

Session::Session()
    : sessionId(sessionCounter++), movie(nullptr), hall(nullptr) {
    time_t now = time(0);
    localtime_s(&startTime, &now);
    seats = nullptr;
}

Session::Session(Movie* movie, Hall* hall, tm& startTime)
    : sessionId(sessionCounter++), movie(movie), hall(hall), startTime(startTime) {
    allocateSeats();
}

Session::Session(Session& other)
    : sessionId(other.sessionId), movie(other.movie), hall(other.hall), startTime(other.startTime) {
    allocateSeats();
    copySeatsFrom(other);
}

Session& Session::operator=(Session& other) {
    if (this != &other) {
        freeSeats();
        movie = other.movie;
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

void Session::copySeatsFrom(Session& other) {
    if (!hall) return;
    for (int i = 0; i < hall->getRows(); i++)
        for (int j = 0; j < hall->getCols(); j++)
            seats[i][j] = other.seats[i][j];
}

int Session::getSessionId() const {
    return sessionId;
}

const tm& Session::getStartTime() const {
    return startTime;
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