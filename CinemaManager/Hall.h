#pragma once
#include <fstream>

class Hall {
private:
	static int counterId;
	int id;
	int rows;
	int cols;
	//void copyFrom(const Hall& other);
	//void free();
	
public:
	Hall();
	Hall(int r, int c);
	/*Hall(const Hall& other);
	Hall& operator=(const Hall& other);*/

	void setId(int newId);

	int getId() const;
	int getRows() const;
	int getCols() const;


};