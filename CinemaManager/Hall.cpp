#include "Hall.h"
#include <iostream>


using namespace std;

Hall::Hall(int r, int c): rows(r), cols(c) {
    allocateSeats();
}

Hall::~Hall() {
    for (int i = 0; i < rows; i++) {
            delete[] seats[i];
    }
    delete[] seats;
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
