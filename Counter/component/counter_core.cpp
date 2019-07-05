#include <iostream>
#include "counter_core.h"

using namespace std;

CounterCore::CounterCore(const CounterCore& m)
{
	container = new int[m.size];
	bound = new int[m.size];
	size = m.size;
	padding = m.padding;
	wrap_around = m.wrap_around;

	for(int i = 0; i < size; i ++)
	{
		container[i] = m.container[i];
		bound[i] = m.bound[i];
	}
}

ostream& operator << (ostream& out, CounterCore& m)
{
	for(int i = 0; i < m.size; i++)
	{
		out.width(m.padding);
		out << m.container[i];
	}
	return out;
}

void CounterCore::reset(int value)
{
	for(int i = 0; i < size; i++)
	{
		container[i] = value;
		bound[i] = value;
	}
}

void CounterCore::dec(void)
{
	int idx = size - 1;

	if(container[idx] > 0)
		container[idx]--;
	else
	{
		while(container[idx] == 0)
		{
			container[idx] = bound[idx];  //carry-over
			idx--;
		}

		if(idx >= 0)
			container[idx]--;
		else
			wrap_around = true;
	}
}
