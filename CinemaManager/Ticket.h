#pragma once

#include "Movie.h"
#include "Hall.h"
#include <ctime>

class Ticket {
private:
	Movie* movie;
    int row;
    int col;
    time_t issueDate;
public:
    Ticket() = default;
    /*~Ticket();*/
    Ticket(Movie* movie, int row, int col);
    Ticket(const Ticket& other);
    Ticket& operator=(const Ticket& other);


    Movie* getMovie();
    int getRow() const;
    int getCol() const;
    time_t getIssueDate() const;
    
    bool isExpired() const;  

    void print() const;
};