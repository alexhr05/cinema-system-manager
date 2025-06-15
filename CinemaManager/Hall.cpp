#include "Hall.h"

using namespace std;

// Конструктор по подразбиране
Hall::Hall(): id(0), rows(0), cols(0)
{
}

// Конструктор с параметри.
Hall::Hall(int r, int c) : id(++counterId), rows(r), cols(c) {
}


void Hall::setId(int newId)
{
    id = newId;
    if (newId >= counterId) {
        counterId = newId+1;
    }
}

int Hall::counterId = 0;

int Hall::getId() const {
    return id;
}

int Hall::getRows() const
{
    return rows;
}

int Hall::getCols() const
{
    return cols;
}

