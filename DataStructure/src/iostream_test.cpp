#include <iostream>

using namespace std;

void cout_test(void)
{
    /*  Note:

    \a Alert (bell, beep)
    \b Backspace
    \n New line
    \r Carriage return
    \t Horizontal tab
    \v Vertical tab
    \' Single quotation mark
    \" Double quotation mark
    \\ Backslash
    \? Question mark

    */

    cout << "EmpName" << "\t\t";
    cout << "EmpNum" << "t\t";
    cout << "Dept Name" << '\t';
    cout << "CCtr" << '\t';
    cout << "Hours" << '\t';
    cout << "Pay" << "\n\n\a";

    cin.ignore();
}
