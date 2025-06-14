#pragma once

#include "Movie.h"
#include "Hall.h"
#include "Session.h"
#include <ctime>

class Ticket {
private:
    static int counterId;
    int id;
    Session* session;
    int row, col;
public:
    Ticket() = default;

    Ticket(Session* session, int row, int col);
    Ticket(const Ticket& other);
    Ticket& operator=(const Ticket& other);
    bool operator==(const Ticket& other);
    void setIssuedDate(tm issuedDate);

    int getId() const;
    int getRow() const;
    int getCol() const;
    Session* getSession() const;

    void print() const;
};