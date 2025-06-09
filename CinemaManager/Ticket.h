#pragma once

#include "Movie.h"
#include "Hall.h"
#include <ctime>

class Ticket {
private:
    static int counterId;
    int id;
	Movie* movie;
    int row;
    int col;
    tm issueDate;
public:
    Ticket() = default;

    Ticket(Movie* movie, int row, int col);
    Ticket(const Ticket& other);
    Ticket& operator=(const Ticket& other);

    void setIssuedDate(tm issuedDate);

    Movie* getMovie() const;
    int getRow() const;
    int getCol() const;
    tm getIssueDate() const;
    int getId() const;
    
    bool isExpired() const;  

    void print() const;
};