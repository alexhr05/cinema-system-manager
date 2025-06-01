// CinemaManager.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include "User.h"
//#include "MyString.h"
#include "MyVector.hpp"

using namespace std;

int main()
{

    MyVector<int> my;
    
    my.add(0);
    my.add(1);
    my.add(2);

    my.print();
}
