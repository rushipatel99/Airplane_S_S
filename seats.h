/*
 * seats.h
 *
 *  Created on: Apr 23, 2019
 *      Author: Rushi
 */

#ifndef SEATS_H_
#define SEATS_H_

#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

class Seats
{
private:
	int rowsize;
	char **seats;
	int digit_to_row(char c);
	int digit_to_column(char c);

public:
	Seats(int new_rowsize);
	~Seats();
	void display_seats(ostream &out);
	bool is_Available(char s_seats[]);
	bool isFull();
	void assign(char s_seats[]);
};



#endif /* SEATS_H_ */
