// CinemaManager.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "User.h"
#include "Hall.h"
#include "Movie.h"
#include "MyString.h"
#include "MyVector.hpp"
#include "SystemManager.h"

using namespace std;

int main()
{
	SystemManager system;
	system.loadHallsFromFiles();
	
	/*Hall hall(5, 5);
	hall.reserveSeat(1,1);
	system.addHall(hall);

	Hall hall2(3,5);
	hall.reserveSeat(0, 0);
	system.addHall(hall2);*/

	system.printHalls();

	


	system.saveHallsToFiles();
	


}
