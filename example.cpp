#include <iostream>

#include "cppinput.hpp"

using namespace std;

class Date {
public:

    friend istream &operator >>(istream &in, Date &d)
    {
        if(!cppinput::input(in, "{}-{}-{}", d.year, d.month, d.day))
            in.setstate(std::ios::failbit);
        return in;
    }

    unsigned year, month, day;
};

int main()
{
    Date d;

    cout << "Enter text in the format \"Date: YYYY-MM-DD\"" << endl; 

    if(!cppinput::input(cin, "Date: {}", d))
        cout << "Incorrectly formatted...";
    else
    {
        cout << "Year: " << d.year << endl;
        cout << "Month: " << d.month << endl;
        cout << "Day: " << d.day << endl;
    }

    return 0;
}
