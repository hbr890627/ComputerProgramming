// Exercise 12.9 Solution: ex12_09.cpp
// Driver program for Package hierarchy.
#include <iostream>
#include <iomanip>
#include "Package.h" // Package class definition
#include "TwoDayPackage.h" // TwoDayPackage class definition
#include "OvernightPackage.h" // OvernightPackage class definition
using namespace std;

int main()
{
   Package package1( "Lou Brown", "1 Main St", "Boston", "MA", 11111, 
      "Mary Smith", "7 Elm St", "New York", "NY", 22222, 8.5, .5 );
   TwoDayPackage package2( "Lisa Klein", "5 Broadway", "Somerville", "MA", 
      33333, "Bob George", "21 Pine Rd", "Cambridge", "MA", 44444, 
      10.5, .65, 2.0 );
   OvernightPackage package3( "Ed Lewis", "2 Oak St", "Boston", "MA", 
      55555, "Don Kelly", "9 Main St", "Denver", "CO", 66666, 
      12.25, .7, .25 );

   cout << fixed << setprecision( 2 );

   // print each package's information and cost

   cout << package1 << "\n\nCost: $" << package1 << endl;

   cout << package2 << "\n\nCost: $" << package2 << endl;

   cout << package3 << "\n\nCost: $" << package3 << endl;
} // end main


