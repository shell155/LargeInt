// main.cpp -- Bob Myers
//
// Driver program to demonstrate the behavior of the MyInt class
// 
// You can add more tests of your own, or write other drivers to test your
// class

#include <iostream>
#include "myint.h"

using namespace std;

MyInt Fibonnaci(MyInt num);

int main()
{

  // demonstrate behavior of the two constructors and the << overload

  MyInt x(12345), y("9876543210123456789"), r1(-1000), r2 = "14H67", r3;

 


  /*// create Fibonacci numbers (stored as MyInts) using +
  cout << "\nAssuming that the Fibonnaci sequence begins 1,1,2,3,5,8,13..."
       << "\n\nThe 10th Fibonnaci number   = " << Fibonnaci(10)
       << "\n\nThe 100th Fibonnaci number  = " << Fibonnaci(100)
       << "\n\nThe 1000th Fibonnaci number = " << Fibonnaci(1000)
       << "\n\nThe 2000th Fibonnaci number = " << Fibonnaci(2000)
       << "\n\n";
       */
}

MyInt Fibonnaci(MyInt num)
{
   MyInt n1 = 1, n2 = 1, n3;
   MyInt i = 2;

   while (i < num)
   {
	n3 = n1 + n2;
	n1 = n2;
	n2 = n3;
	i++;
   }

   return n2;
}
