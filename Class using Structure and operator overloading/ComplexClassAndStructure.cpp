//#include "stdafx.h" uncomment for visual studio
#include <iostream>
using namespace std;
#include "complex.h"

int main()
{
    double real1, real2, imag1, imag2;
	Complex n1 (3.4, 6.3), n2(3.5, 7.6), temp;
    Complex n3, n4, n5;

    cout << "\n n1 is: ";  n1.print();
	cout << "\n n2 is: ";  n2.print();
   
    cout << "\nFor 1st complex number";
    cout << "\nEnter real and imaginary part respectively:\n";
    cin >>  real1 >> imag1 ;
    n1.Setcomplex(real1, imag1);

    cout << "\nFor 2nd complex number";
    cout << "\nEnter real and imaginary part respectively:\n";
	cin >> real2 >> imag2;
	n2.Setcomplex(real2, imag2);
	cin.ignore(256,'\n');
	
    cout << "\n new n1 is: ";  n1.print();
	cout << "\n new n2 is: ";  n2.print();

    n1 = n1.add(n2);
    cout << "\n n1=n1+n2 is:";	n1.print();	
	
	cout <<"\nType in real and imaginary parts of a complex number as: (3.45,7.89)\n";
	cin >> n3;   cout << "n3 is: " << n3 <<endl;
	
	cout <<"\nType in real and imaginary parts of a complex number as: (3.45,7.89)\n";
	cin >> n4;   cout << "n4 is: " << n4 <<endl;
	
    n3 = n3+n4;
 	cout << "\n n3=n3+n4 is:" << n3;
    n4 = n3-n4;
    cout << "\n n4=n3-n4 is:" << n4;

    return 0;
}


