//============================================================================
// Name        : BinaryFile.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "FileDB.h"

using namespace std;

void usage_demo(void)
{
    BinaryFileIO file_io;
    Person entry;

    // load the data in the db file
    if (file_io.Import("db.dat"))
    {
        file_io.Display();
    }

    // prompt user to enter the new info
    cout << "Set database info...\n";
    cout << "Name: ";
    cin.getline(entry.name, 40);

    cout << "Age: ";
    (cin >> entry.age).get();// add the .get() to clear the newline character

    cout << "Salary: ";
    (cin >> entry.salary).get();// note .getline() clears its own newline character

    file_io.SetPersonName(entry.name, 40);
    file_io.SetAge(entry.age);
    file_io.SetSalary(entry.salary);

    // save the new user-entered data
    if (file_io.Export("db.dat"))
      cout << "\nDatabase saved!\n";
    else
      cout << "\nUnable to save database!\n";

    // give the user a chance to look things over before quitting
    cout << "\n[hit enter]";
    cin.get();
}

int main()
{
    usage_demo();
	return 0;
}
