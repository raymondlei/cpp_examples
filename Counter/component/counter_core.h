#ifndef COUNTER_CORE_H_
#define COUNTER_CORE_H_

#include <iostream>

using namespace std;

class CounterCore
{
public:

	//constructors
	CounterCore() : CounterCore(1) { }
	CounterCore(int size)
	{
		this->size = size;
		this->container = new int[size];
		this->bound = new int[size];
		this->padding = 2;
		wrap_around = false;
	}
	CounterCore(const CounterCore& m);  //copy constructor

	void setPadding(int value) { padding = value; }
	int getSize() const { return size; }
	bool isWrapAround() { return wrap_around; }

	void reset(int value);
	void dec(void);

	friend ostream& operator <<(ostream& out, CounterCore& m);


private:
	int *container;
	int *bound;
	int size;
	int padding;
	bool wrap_around;
};


#endif /* COUNTER_CORE_H_ */
