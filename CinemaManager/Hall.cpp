#include "Hall.h"
#include <iostream>


using namespace std;


void Hall::copyFrom(const Hall& other)
{
    id = other.id;
    rows = other.rows;
    cols = other.cols;
    seats = new char* [rows];
    for (int i = 0; i < rows; i++) {
        seats[i] = new char[cols];
        for (int j = 0; j < cols; j++) {
            seats[i][j] = other.seats[i][j];
        }
    }
}

void Hall::free()
{
    for (int i = 0; i < rows; i++) {
        delete[] seats[i];
    }
    delete[] seats;
}

Hall::Hall(): id(0), rows(0), cols(0), seats(new char*[1])
{
}

Hall::Hall(int r, int c): rows(r), cols(c) {
    id = ++counterId;
    allocateSeats();
}

Hall::Hall(const Hall& other)
{
    copyFrom(other);
}

Hall& Hall::operator=(const Hall& other)
{
    if (this != &other) {
        free();
        copyFrom(other);
    }

    return *this;

}

Hall::Hall(int r, int c, char** seats) : id(++counterId), rows(r), cols(c), seats(seats) {
}

Hall::~Hall() {
    free();
}

void Hall::allocateSeats() {
    seats = new char* [rows];
    for (int i = 0; i < rows; i++) {
        seats[i] = new char[cols];
        for (int j = 0; j < cols; j++) {
            seats[i][j] = 'F'; 
        }
    }
}

void Hall::displaySeats() const{
    cout << "Display" << endl;
    cout<<"rows="<<rows<<endl;
    cout << "cols=" << cols << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << seats[i][j] << " ";
        }
        cout << endl;
    }
}

bool Hall::reserveSeat(int row, int col) {
    if (row < 0 || row >= rows || col < 0 || col >= cols) return false;

    if (seats[row][col] == 'F') {
        seats[row][col] = 'R';
        return true;
    }

    return false;
}


bool Hall::cancelReservation(int row, int col) {
    if (row < 0 || row >= rows || col < 0 || col >= cols) return false;
    if (seats[row][col] == 'R') {
        seats[row][col] = 'F';
        return true;
    }

    return false;
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

char** Hall::getSeats() const
{
    return seats;
}

char Hall::getSeat(int r, int c) const
{
    return seats[r][c];
}


//std::ostream& operator<<(std::ostream& out, const Hall& hall) {
//    out << hall.getId() << " " << hall.getRows() << " " << hall.getCols() << '\n';
//    for (int i = 0; i < hall.getRows(); ++i) {
//        for (int j = 0; j < hall.getCols(); ++j) {
//            out << seats[i][j] << ' ';
//        }
//        out << '\n';
//    }
//    return out;
//}
