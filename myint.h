// starter file for MyInt class header
#include <cmath>
#include <iostream>
#include <cstring>
using namespace std;

class MyInt
{
    // these overload starters are declared as friend functions

    friend MyInt operator+(const MyInt &x, const MyInt &y);
    friend MyInt operator*(const MyInt &x, const MyInt &y);
    // add in multiplication, as well

    friend bool operator<(const MyInt &x, const MyInt &y);
    friend bool operator==(const MyInt &x, const MyInt &y);
    friend bool operator!=(const MyInt &x, const MyInt &y);
    friend bool operator>(const MyInt &x, const MyInt &y);
    friend bool operator<=(const MyInt &x, const MyInt &y);
    friend bool operator>=(const MyInt &x, const MyInt &y);

    // add in the other comparison overloads, as well
    friend ostream& operator<<(ostream& out,  const MyInt& obj);
    friend ostream& operator>>(istream& in,   MyInt& obj);

    // declare overloads for input and output (MUST be non-member functions)
    //  you may make them friends of the class

public:
    MyInt(int n = 0); // first constructor
    MyInt(const char *n);
    ~MyInt();
    MyInt(const MyInt &copy);
    MyInt &operator=(const MyInt &copy);
    MyInt operator++(int x);
    MyInt operator++();
    int getsize()const;
    int getcap()const;

    

    // be sure to add in the second constructor, and the user-defined
    //  versions of destructor, copy constructor, and assignment operator

private:
    // member data (suggested:  use a dynamic array to store the digits)
    unsigned int *myint;
    unsigned int myintsize;
    unsigned int myintcapacity;
    void allocate(int);
    void insert(int num);
    void set(const char*);
    void reverse(unsigned int array[] , unsigned int& arraysize);
};


