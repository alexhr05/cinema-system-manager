#pragma once

#include "Movie.h"
#include "Hall.h"
#include <ctime>

class Ticket {
private:
	Movie movie;
    int row;
    int col;
    time_t issueDate;
public:
    Ticket(Movie& movie, int row, int col);

    Movie getMovie() const;
    int getRow() const;
    int getCol() const;
    time_t getIssueDate() const;
    
    bool isExpired() const;  

    void print() const;
};