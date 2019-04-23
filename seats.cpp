/*
 * seats.cpp
 *
 *  Created on: Apr 23, 2019
 *      Author: Rushi
 */

#include"seats.h"

Seats::Seats(int new_rowsize):rowsize(new_rowsize)
{
	seats = new char*[new_rowsize];
	for(int i = 0; i < rowsize; i++)
	{
		seats[i] = new char[4];
		seats[i][0] = 'A';
		seats[i][1] = 'B';
		seats[i][2] = 'C';
		seats[i][3] = 'D';
	}
}

Seats::~Seats()
{
	for(int i = 0; i < rowsize;i++)
		delete[]seats[i];

	delete[]seats;
}

void Seats::display_seats(ostream &out)
{
	for(int i = 0; i < rowsize; i++)
	{
		out << i+1;
		for(int j = 0; j < 4; j++)
		{
			out <<" "<<seats[i][j];
		}
		out << endl;
	}

}

bool Seats::is_Available(char s_seats[])
{
	int r = digit_to_row(s_seats[0]);
	int col = digit_to_column(s_seats[1]);

	if(r < 1 || r > rowsize)
		return false;

	return seats[r-1][col] != 'X';
}

bool Seats::isFull()
{
	for(int i = 0; i < rowsize; i++)
		for(int j = 0; j < 4; j++)
			if(seats[i][j] != 'X')
				return false;

	return true;
}
void Seats::assign(char s_seats[])
{
	int r = digit_to_row(s_seats[0]);
	int col = digit_to_column(s_seats[1]);
	seats[r-1][col] = 'X';
}

int Seats::digit_to_row(char c)
{
	return c - '0';
}

int Seats::digit_to_column(char c)
{
	if(c >= 'a' && c <= 'z')
		return c-'a';

	else
		return c - 'A';
}



