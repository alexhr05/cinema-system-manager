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
    void copySeatsFrom(const Session& other);

public:
    Session();
    Session(Movie* movie, Hall* hall, tm& startTime);
    Session(const Session& other);
    Session& operator=(const Session& other);
    bool operator==(const Session& other);
    ~Session();

    void setId(int id);
    void setNewId();

    int getId() const;
    const tm& getStartTime() const;
    Hall* getHall() const;
    Movie* getMovie() const;
    char** getSeats();


    bool reserveSeat(int row, int col);
    bool isSeatTaken(int row, int col) const;
    void displaySeats() const;
    bool isExpired() const;

    char getSeat(int r, int c) const;
    bool cancelReservation(int row, int col);
    void print() const;


};
