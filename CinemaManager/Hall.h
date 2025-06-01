#pragma once

class Hall {
private:
	int rows;
	int cols;
	char** isSeatTaken;
public:
	Hall(int r, int c);
	~Hall();

	void allocateSeats();
	void displaySeats() const;
	bool reserveSeat(int row, int col);
	bool cancelReservation(int row, int col);
};