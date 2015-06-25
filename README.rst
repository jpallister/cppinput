C++ Input
=========

C++ Input is a header library to perform formatted input in C++, licensed under the LGPL.

Examples
--------

For example, a float and an unsigned integer can be read:

.. code:: c++

    float f;
    unsigned u;

    // Read a float, then an integer
    cppinput::input(cin, "{} {}", f, u); 


User defined types can be input as long as they provide an input stream operator.

.. code:: c++
 
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


    Date d;
    cppinput::input(cin, "Date: {}", d);
