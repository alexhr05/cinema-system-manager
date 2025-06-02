#pragma once

class Hall {
private:
	static int id;
	int rows;
	int cols;
	char** seats;
public:
	Hall(int r, int c);
	~Hall();

	void allocateSeats();
	void displaySeats() const;
	bool reserveSeat(int row, int col);
	bool cancelReservation(int row, int col);

	int getId() const;
	int getRow() const;
	int getCol() const;
	char** getSeats() const;

};