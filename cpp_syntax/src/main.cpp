//============================================================================
// Name        : cpp_syntax.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdarg.h>
#include <conio.h>

using namespace std;


/*
 * demonstrate variable-arg list
 */
float AverageInts(int num1, ...)
{

   // Some local variables
   //
   int sum = 0;
   int count = 0;
   int curNum = num1;

   // Initialize variable arguments
   va_list loc;
   va_start(loc, num1);

   // 0 is used as the argument-list terminator
   //
   while (curNum != 0)
   {
      sum += curNum; // Add the numbers
      count++; // increment count
      curNum = va_arg(loc, int); // update current num
   }

   // Reset variable arguments
   //

   va_end(loc);
   return sum ? (float(sum) / float(count)) : 0.0f ;
}

static void var_list_demo(void)
{
    cout << "Average: " << AverageInts(1, 2, 3, 4, 0);
    cout << "\nAverage: " << AverageInts(2, 3, 4, 0);
    cout << "\nAverage: " << AverageInts(3, 4, 0);
    cout << "\nAverage: " << AverageInts(4, 0) << '\n';
}

int main()
{
	var_list_demo();

	return 0;
}
