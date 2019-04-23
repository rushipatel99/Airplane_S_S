//============================================================================
// Name        : AIRPLANE_S_S.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include"seats.h"

using namespace std;

int main() {

	int RowSize;
	cout << "How many rows for the plane?"<<endl;
	cin >> RowSize;
	Seats TestSE(RowSize);

	while(1)
	{
		TestSE.display_seats(cout);
		cout << "Which seat would you like? (e/E to exit)\n";
		char seat[4];
		cin.getline(seat, 4);

		if (seat[0] == 'e' || seat[0] == 'E')
		{
			break;
		}

		if (TestSE.is_Available(seat))
		{
			TestSE.assign(seat);
			cout << "assigned\n";
		}
		else
		{
			cout << "Sorry! Seat is not available\n";
		}

		if (TestSE.isFull())
		{
			cout << "Sorry! Plane is all booked\n";
			break;
		}
	}

	return 0;
}
