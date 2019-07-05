#include <iostream>
#include "MatrixClass.h"

using namespace std;

static void test_1(void)
{
    // dimensions
    int row = 5;
    int col = 10;

    // dynamic allocation
    int** ary = new int*[row];
    for(int i = 0; i < row; ++i)
        ary[i] = new int[col];

    // fill
    for(int i = 0; i < row; ++i)
      for(int j = 0; j < col; ++j)
        ary[i][j] = i;

    // print
    for(int i = 0; i < row; ++i)
    {
    	for(int j = 0; j < col; ++j)
    		std::cout << ary[i][j] << ",";
    	cout << endl;
    }
    cout << endl;

    // free
    for(int i = 0; i < row; ++i)
      delete[] ary[i];
    delete[] ary;
}

static void test_2(void)
{
    MatrixLib matrix = MatrixLib(5, 10);
    matrix.create();
    matrix.fill(5);
    matrix.at(1, 2) = 0;
    cout << matrix << endl;
//    matrix.~MatrixLib();

    MatrixLib cpMatrix = MatrixLib(matrix);
    cout << cpMatrix << endl;

    MatrixLib matrix_2 = MatrixLib(5, 10);
    matrix_2.create();
    matrix_2.fill(1);
    cout << matrix_2 << endl;

    matrix_2 = matrix;

    cout << matrix_2 << endl;
}

static void test_3(void)
{
    MatrixLib matrix = MatrixLib(5, 10);
    matrix.create();
    matrix.fill(5);
    matrix.at(1, 2) = 0;

    cout << matrix << endl;

    MatrixLib sum(5, 10);
    sum.create();
    sum.fill(1);
    cout << sum << endl;

    //sum = matrix.add(matrix);
    sum = matrix + matrix;
    cout << sum << endl;
}

static void test_4(void)
{
    MatrixLib matrix_1 = MatrixLib(5, 10);
    matrix_1.create();
    matrix_1.fill(2);

    MatrixLib matrix_2 = MatrixLib(10, 5);
    matrix_2.create();
    matrix_2.fill(1);

    matrix_1.fill(5);
    matrix_1.at(1, 2) = 0;

    MatrixLib sum = matrix_1 * matrix_2;
    cout << sum << endl;
}

int main()
{
//    test_1();
//    test_2();
    test_3();
//	  test_4();

	return 0;
}
