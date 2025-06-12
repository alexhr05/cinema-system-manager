#pragma once
#include <fstream>

class Hall {
private:
	static int counterId;
	int id;
	int rows;
	int cols;
	//char** seats;
	void copyFrom(const Hall& other);
	void free();
	
	/*friend std::ostream& operator<<(std::ostream& out, Hall& hall);
	friend std::istream& operator>>(std::istream& in, Hall& hall);*/
public:
	Hall();
	Hall(int r, int c);
	Hall(const Hall& other);
	Hall& operator=(const Hall& other);
	//Hall(int r, int c, char** seats);
	/*~Hall();*/

	/*void allocateSeats();
	void displaySeats() const;
	bool reserveSeat(int row, int col);
	bool cancelReservation(int row, int col);*/

	void setId(int newId);

	int getId() const;
	int getRows() const;
	int getCols() const;
	/*char** getSeats() const;
	char getSeat(int r, int c) const;*/

};