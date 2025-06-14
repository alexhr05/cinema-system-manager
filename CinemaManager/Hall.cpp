#include "Hall.h"
//#include <iostream>


using namespace std;


//void Hall::copyFrom(const Hall& other)
//{
//    id = other.id;
//    rows = other.rows;
//    cols = other.cols;
//}
//

Hall::Hall(): id(0), rows(0), cols(0)
{
}

Hall::Hall(int r, int c) : id(++counterId), rows(r), cols(c) {
}

//Hall::Hall(const Hall& other)
//{
//    copyFrom(other);
//}
//
//Hall& Hall::operator=(const Hall& other)
//{
//    if (this != &other) {
//        copyFrom(other);
//    }
//
//    return *this;
//
//}


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

