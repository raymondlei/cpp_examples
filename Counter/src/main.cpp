//============================================================================
// Name        : Counter.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "counter_core.h"

using namespace std;

int main()
{
	CounterCore counter(5);
	counter.reset(1);
	cout << counter << endl;

	while(counter.isWrapAround() == false)
	{
		counter.dec();
		cout << counter << endl;
	}
	return 0;
}
