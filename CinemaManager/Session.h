#pragma once
#include "Hall.h"
#include "Movie.h"
#include <ctime>
#include <fstream>

class Session {
private:
    static int sessionCounter;
    int sessionId;
    Movie* movie;
    Hall* hall;
    tm startTime;
    char** seats;

    void allocateSeats();
    void freeSeats();
    void copySeatsFrom(Session& other);

public:
    Session();
    Session(Movie* movie, Hall* hall, tm& startTime);
    Session(Session& other);
    Session& operator=(Session& other);
    ~Session();

    int getId() const;
    const tm& getStartTime() const;

    bool reserveSeat(int row, int col);
    bool isSeatTaken(int row, int col) const;
    void displaySeats() const;
};
