#include <iostream>
#include <sstream>
#include <assert.h>

#include "cppinput.hpp"

using namespace std;

template<typename T>
void test_single(string fmt, string data, T expected)
{
    stringstream ss(data);
    T val;
    bool success;

    success = cppinput::input(ss, fmt, val);

    if(val != expected || !success)
    {
        cout << "Test failure (\""<< fmt <<"\"): \"" << val <<
            "\" != \"" << expected << "\"" << endl;
    }
}

template<typename T>
void test_single_fail(string fmt, string data, T expected)
{
    stringstream ss(data);
    T val;
    bool success;

    success = cppinput::input(ss, fmt, val);

    if(val == expected || success)
    {
        cout << "Test failure (\""<< fmt <<"\"): ";
        
        if(success)
            cout << "Success indicated";
        else
            cout << "\"" << val << "\" == \"" << expected << "\"";
        cout << endl;
    }
}

template<typename T1, typename T2>
void test_double(string fmt, string data, T1 expected1, T2 expected2)
{
    stringstream ss(data);
    T1 val1;
    T2 val2;
    bool success;

    success = cppinput::input(ss, fmt, val1, val2);

    if(val1 != expected1 || val2 != expected2 || !success)
    {
        cout << "Test failure (\""<< fmt <<"\"): \"" << val1 <<
            "\" != \"" << expected1 << "\" or \"" <<
            val2 << "\" != \"" << expected2 << "\"" << endl;
    }
}

template<typename T>
void test_single_ss(string fmt, string data, T expected)
{
    T val;
    bool success;

    success = cppinput::input(data, fmt, val);

    if(val != expected || !success)
    {
        cout << "Test failure (\""<< fmt <<"\"): \"" << val <<
            "\" != \"" << expected << "\"" << endl;
    }
}

void test_none(string fmt, string data)
{
    stringstream ss(data);
    bool success;

    success = cppinput::input(ss, fmt);

    if(!success)
    {
        cout << "Test failure (\""<< fmt <<"\")" << endl;
    }
}

void test()
{
    cout << "Testing numericals..." << endl;
    test_single("{}", "1", 1u);
    test_single("{}", "1", 1l);
    test_single("{}", "1", 1.0f);
    test_single("{}", "1.3", 1.3f);
    test_single("{}", "1.3", 1.3);
    test_single_fail("{}.3", "1", 1.3);
    test_single_fail("1..", "1.3", 1.3f);

    cout << "Testing strings..." << endl;
    test_single<string>("{}", "abc", "abc");
    test_single_fail<string>("{}cd", "abcd", "ab");

    cout << "Testing string compositions..." << endl;
    test_single<string>("ab{}", "abcd", "cd");
    test_single<string>("{}", "abc d", "abc");
    test_single<string>("{} abc", "abc abc", "abc");
    test_single<string>("abc{} fg", "abcde fg", "de");
    test_single<string>("abc{} fg", "abcdeee fg", "deee");
    test_single<string>("abc{} fg", "abcdeee fg", "deee");

    cout << "Testing multiple inputs..." << endl;
    test_double("{} {}", "1 1", 1, 1);
    test_double("{} {}", "1.5 1.5", 1.5, 1.5);
    test_double("{}.{}", "1.5.1.5", 1.5, 1.5);
    test_double("{}.{}", "1.5.1.5", 1, 5);
    test_double("{}.{}", "1.5.1.5", 1.5, 1);

    cout << "Testing string stream..." << endl;
    test_single_ss("{}", "1", 1u);
    test_single_ss("{}", "1", 1l);
    test_single_ss("{}", "1", 1.0f);
    test_single_ss("{}", "1.3", 1.3f);
    test_single_ss("{}", "1.3", 1.3);

    cout << "Testing strings with no placeholders..." << endl;
    test_none("abc", "abc");
    test_none("abc", "abcd");
}

int main()
{
    test();
    cout << "Done." << endl;

    return 0;
}
