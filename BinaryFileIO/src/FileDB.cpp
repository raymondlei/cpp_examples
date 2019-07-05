
#include <iostream>  // for cin, cout, endl
#include <fstream>   // for ifstream, ofstream, ios_base

#include "FileDB.h"

using namespace std;

bool BinaryFileIO::Import(const char *file_name)
{
    // this function takes a pointer to a Person struct
    // that will be filled with the data in the file

    // first parameter is the name of the file
    // second is the open flags.
    //    `in` says you will read from the file
    //    `binary` says you will read binary data instead of simple text
    std::ifstream file_handle(file_name); //, ios_base::in || ios_base::binary);

    if(!file_handle.is_open())
        return false;

    // the file is open; tell the read function to look at `per` as a
    // char pointer instead of a Person pointer so that `fin` can place
    // one byte at a time into the struct
    // the second parameter tells read() how many bytes to read
    // Note: do not use the ">>" operator to read from a binary file
    file_handle.read((char*)&person_info, sizeof(Person));
    file_handle.close();// close the file - not necessary, but we should be neat

    return true;
}

bool BinaryFileIO::Export(const char* file_name)
{
    // this function takes a pointer to a Person struct
    // that will be written into the file

    // these flags say:
    //    `out` - we will be writing data into the file
    //    `binary` - we will be writing binary data and not simple text
    //    `trunc` - if the file already exists, truncate (wipe out) the existing data
    ofstream fout(file_name, ios_base::out | ios_base::binary | ios_base::trunc);

    if(!fout.is_open())
        return false;

    fout.write((const char*)&person_info, sizeof(Person));  //serialize object
    fout.close();

    return true;
}

void BinaryFileIO::Display(void)
{
    // print what we loaded into our Person struct
    cout << "Loaded Database...\n";
    cout << "Name = " << person_info.name << endl;
    cout << "Age = " << person_info.age << endl;
    cout << "Salary = " << person_info.salary << endl;
    cout << endl;
}

void BinaryFileIO::SetPersonName(std::string str, int length)
{
    str.copy(person_info.name, length, 0);
}

void BinaryFileIO::SetAge(int value)
{
    person_info.age = value;
}

void BinaryFileIO::SetSalary(float value)
{
    person_info.salary = value;
}

