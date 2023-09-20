#include <iostream>
#include "myint.h"

using namespace std;

int C2I(char c)
// converts character into integer (returns -1 for error)
{
    if (c < '0' || c > '9')
        return -1;    // error
    return (c - '0'); // success
}

char I2C(int x)
// converts single digit integer into character (returns '\0' for error)
{
    if (x < 0 || x > 9)
        return '\0';                     // error
    return (static_cast<char>(x) + '0'); // success
}

// Add in operator overload and member function definitions

MyInt::MyInt(int n)
    : myintsize{0},
      myintcapacity{5},
      myint{new unsigned int[myintcapacity]}
{
    if (n < 0)
        n = 0;

    insert(n);
}

MyInt::MyInt(const char *n) 
    : myintsize{0},
      myintcapacity{5},
      myint{new unsigned int[myintcapacity]}
{
    set(n);
}

MyInt::~MyInt()
{
    delete[] myint;
}

MyInt::MyInt(const MyInt &copy)
    : myintsize{copy.myintsize},
      myintcapacity{copy.myintcapacity},
      myint{new unsigned int[copy.myintcapacity]}
{
    for (int i = 0; i < myintsize; i++)
        myint[i] = copy.myint[i];
}

MyInt &MyInt::operator=(const MyInt &copy)
{
    if (this != &copy)
    {
        myintsize = copy.myintsize;
        myintcapacity = copy.myintcapacity;
        myint = new unsigned int[copy.myintcapacity];
        for (int i = 0; i < myintsize; i++)
            myint[i] = copy.myint[i];
    }

    return *this;
}

MyInt MyInt::operator++(int x)
{
    MyInt old = x;
    ++(x);
    return old;
}

MyInt MyInt::operator++()
{
    ++(*myint);
    return *this;
}

int MyInt::getsize() const
{
    return myintsize;
}

int MyInt::getcap() const
{
    return myintcapacity;
}

void MyInt::insert(int num) //function that seperates digit individually and adds to array
{
    if (myintsize == myintcapacity)
        allocate(myintsize + 5);

    int digit;

    if (num == 0)
    {
        myint[myintsize] = 0;
        myintsize++;
    }

    while (num > 0)
    {
        if (myintsize >= myintcapacity)
            allocate(myintsize + 5); 
        digit = num % 10;
        myint[myintsize] = digit;
        num /= 10;
        myintsize++;
    }

    reverse(myint, myintsize);
}

void MyInt::set(const char *n) //funct that take c- style string that turns the indivi char to myInt 
{
    unsigned int tempsize = (unsigned)strlen(n);
    if (tempsize == 0)
    {
        myint[0] = 0;
        myintsize = 1;
        return;
    }

    myintsize = tempsize;
    allocate(myintsize + 5);
    for (int i = 0; i < tempsize; i++)
    {
        if (C2I(n[i]) == -1)
        {
            myint[0] = 0;
            myintsize = 1;
            allocate(myintsize + 5);
            return;
        }
        myint[i] = C2I(n[i]);
    }

}

void MyInt::reverse(unsigned int *myint, unsigned int &intsize) //reverse the myInt array's content
{
    for (int i = 0; i < intsize / 2; i++)
    {
        int temp = myint[i];
        myint[i] = myint[intsize - 1 - i];
        myint[intsize - 1 - i] = temp;
    }
}

void MyInt::allocate(int n)  //currrent size ca not be > 5 ; allocates space 
{
    if (n < myintsize)
        return;

    myintcapacity = n;
    if (myintcapacity - myintsize > 5)
    {
        myintcapacity = myintsize + 5;
    }
    unsigned int *temp = new unsigned int[myintcapacity];
    for (int i = 0; i < myintsize; i++)
    {
        temp[i] = myint[i];
    }
    delete[] myint;
    myint = temp;
    temp = nullptr;
}

//operator overloads functions below

bool operator<(const MyInt &x, const MyInt &y)
{
    if (x.myintsize != y.myintsize)
    {
        return x.myintsize < y.myintsize;
    }
    for (int i = x.myintsize - 1; i >= 0; i--)
    {
        if (x.myint[i] != y.myint[i])
        {
            return x.myint[i] < y.myint[i];
        }
    }
    return false;
}

bool operator>(const MyInt &x, const MyInt &y)
{
    return !(x < y) && (y != x);
}

bool operator<=(const MyInt &x, const MyInt &y)
{
    if (x.myintsize != y.myintsize)
    {
        return x.myintsize < y.myintsize;
    }
    for (int i = x.myintsize - 1; i >= 0; i--)
    {
        if (x.myint[i] != y.myint[i])
        {
            return x.myint[i] < y.myint[i] || x.myint[i] == y.myint[i];
        }
    }
    return true;
}

bool operator>=(const MyInt &x, const MyInt &y)
{
    if (x.myintsize != y.myintsize)
    {
        return x.myintsize > y.myintsize;
    }
    for (int i = x.myintsize - 1; i >= 0; i--)
    {
        if (x.myint[i] != y.myint[i])
        {
            return x.myint[i] > y.myint[i] || x.myint[i] == y.myint[i];
        }
    }
    return true;
}

bool operator==(const MyInt &x, const MyInt &y)
{
    bool flag = false;

    if (x.myintsize != y.myintsize)
        return false;

    for (int i = 0; i < x.myintsize; i++)
    {
        if (x.myint[i] != y.myint[i])
            return false;

        if (x.myint[i] == y.myint[i])
            flag = true;
    }

    return flag;
}

bool operator!=(const MyInt &x, const MyInt &y)
{
    return !(x == y);
}

ostream &operator<<(ostream &out, const MyInt &obj)
{
    for (int i = 0; i < obj.myintsize; i++)
        out << obj.myint[i];

    return out;
}

MyInt operator+(const MyInt &x, const MyInt &y) //adds two myints objects
{
    MyInt temp;
    temp.myintsize = 0;
    int carry = 0;
    int i = x.myintsize - 1; //starting at the last digits
    int j = y.myintsize - 1;
    while (i >= 0 || j >= 0)
    {
        if (temp.getcap() >= temp.getsize()) //allocating accordingly based on the size of the array
        {
            temp.allocate(temp.getsize() + 5);
        }
        int sum = 0;
        ;
        if (i >= 0)
        {
            sum += x.myint[i];
            i--;
        }
        if (j >= 0)
        {
            sum += y.myint[j];
            j--;
        }
        sum += carry;
        temp.myint[temp.myintsize] = sum % 10;
        carry = sum / 10;
        temp.myintsize++;
    }

    temp.reverse(temp.myint, temp.myintsize); 

    return temp;
}


