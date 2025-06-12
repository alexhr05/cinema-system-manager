#pragma once

#include "Movie.h"
#include "Hall.h"
#include "Session.h"
#include <ctime>

class Ticket {
private:
    static int counterId;
    int id;
    Session session;
public:
    Ticket() = default;

    Ticket(Session session);
    Ticket(const Ticket& other);
    Ticket& operator=(const Ticket& other);

    void setIssuedDate(tm issuedDate);

    int getId() const;
    Session getSession() const;
    
    /*bool isExpired() const;  */

    void print() const;
};