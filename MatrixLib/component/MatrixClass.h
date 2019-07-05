#include <iostream>

#ifndef MATRIX_CLASS_H_
#define MATRIX_CLASS_H_

using namespace std;

class MatrixLib
{
public:

	//constructor
    MatrixLib(int row, int col)
	{
    	this->row = row;
    	this->col = col;
    	this->p = 0;
	}

    MatrixLib(const MatrixLib& m);
    ~MatrixLib() { destroy(); }

    int nRows(void) { return row; }
    int nCols(void) { return col; }

    int& at(int row, int col);
    void create(void);
    void fill(int value);

    MatrixLib add(MatrixLib& m);
    MatrixLib subtract(MatrixLib& m);
    MatrixLib multiply(MatrixLib& m);

//    MatrixLib negate() {}
//    MatrixLib transpose() {}

    //operators overload
    friend ostream& operator <<(ostream& out, MatrixLib& m);
    friend istream& operator >>(istream& in, MatrixLib& x);

    MatrixLib& operator = (const MatrixLib& m);
    MatrixLib  operator + (MatrixLib& m) { return this->add(m); }
    MatrixLib  operator - (MatrixLib& m) { return this->subtract(m); }
    MatrixLib  operator * (MatrixLib& m) { return this->multiply(m); }

private:
    int** allocate(int row, int col)
    {
        this->row = row;
        this->col = col;

        int **ptr = new int*[row];
        for(int i = 0; i < row; i++)
        {
            ptr[i] = new int[col];
        }

        return ptr;
    }

    void destroy()
    {
        // free
        for(int i = 0; i < row; ++i)
          delete[] p[i];
        delete[] p;
    }

    int **p;
    int row, col;
};

#endif /* MATRIX_CLASS_H_ */
