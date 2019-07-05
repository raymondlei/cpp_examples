#include <iostream>
#include <fstream>
#include "MatrixClass.h"

using namespace std;

//copy constructor
MatrixLib::MatrixLib(const MatrixLib& m)
{
    p = allocate(m.row, m.col);

    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            p[i][j] = m.p[i][j];
}

void MatrixLib::create(void)
{
    //Constructor
    p = allocate(row, col);
}

void MatrixLib::fill(int value)
{
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
        	p[i][j] = value;
}

int& MatrixLib::at(int row, int col)
{
    return p[row][col];
}

MatrixLib MatrixLib::add(MatrixLib& m)
{
	if(!((row == m.row) && (col == m.col)))
	{
		cout << "matrices incompatible\n";
		exit(1);
	}

	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
			at(i,j) = at(i,j) + m.at(i,j);

	return *this;
}

MatrixLib MatrixLib::subtract(MatrixLib& m)
{
	if(!((row == m.row) && (col == m.col)))
	{
		cout << "matrices incompatible\n";
		exit(1);
	}

	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
			at(i,j) = at(i,j) - m.at(i,j);

	return *this;
}

MatrixLib MatrixLib::multiply(MatrixLib& m)
{
	int sum = 0;

	if(col != m.row)
	{
		exit(1);
	}

	MatrixLib temp(row, m.col);

	for(int i = 0; i <= row; i++)
		for(int j = 0; j <= m.col; j++)
		{
			sum = 0;
			for(int k = 0; k <= col; k++)
				sum = sum + p[i][k] * m.at(k,j);

			temp.at(i,j) = sum;
		}

	return temp;
}
//serialize
ostream& operator <<(ostream& out, MatrixLib& m)
{
    for(int i = 0; i < m.row; i++)
    {
        for(int j = 0; j < m.col; j++)
            out << m.at(i, j) << ",";

        out << endl;
    }

    return out;
}

//de-serialize
istream& operator >>(istream& in, MatrixLib& m)
{
    int row, col;

    in >> row >> col;

    if((m.row == row) &&
        (m.col == col))
    {
        for(int i = 0; i < row; i++)
           for(int j=1; j < col; j++)
              in >> m.at(i,j);
    }

    return in;
}

MatrixLib& MatrixLib::operator = (const MatrixLib& m)
{
    if(p == m.p) return *this;  //do nothing

    allocate(m.row, m.col);

    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
        {
            p[i][j] = m.p[i][j];
        }

    return *this;
}
