//Complex.cpp
//Complex class member-function definitions.
//#include "stdafx.h"  uncomment for visual studio
#include <iostream>
#include "complex.h" // Complex class definition

using namespace std;

ostream &operator<<( std::ostream &output, const Complex &cobject )
{
 cout << "\n(" << cobject.structcomplex.real << ", " << cobject.structcomplex.imaginary << 'i' << ")\n";
 return output;	
}

istream &operator>>( istream &input, Complex &cobject )
{
 input.ignore();
 input >> cobject.structcomplex.real;
 input.ignore();
 input >> cobject.structcomplex.imaginary;
 input.ignore();
 input.ignore(256, '\n');  //skip all in current input buffer until newline
 return input;
}

// Constructor
Complex::Complex(double realPart, double imaginaryPart)
	: structcomplex ({ realPart, imaginaryPart })
{
// Setcomplex(realPart, imaginaryPart );
 } // end Complex constructor

 // addition operator
void Complex::print() const
{
 cout << "(" << structcomplex.real << ", " << structcomplex.imaginary << 'i' << ")";
 }


Complex Complex::add(const Complex& n2) const
{
      Complex temp;

      temp.structcomplex.real = this->structcomplex.real + n2.structcomplex.real;
      temp.structcomplex.imaginary = this->structcomplex.imaginary + n2.structcomplex.imaginary;

      return temp;
}
Complex Complex::operator+( const Complex &operand2 ) const
 {
 return Complex( structcomplex.real + operand2.structcomplex.real,
 structcomplex.imaginary + operand2.structcomplex.imaginary );
 } // end function operator+

 // subtraction operator
 Complex Complex::operator-( const Complex &operand2 ) const
 {
 return Complex( structcomplex.real - operand2.structcomplex.real,
 structcomplex.imaginary - operand2.structcomplex.imaginary );
 } // end function operator-

void Complex::Setcomplex(double real, double imaginary )
{
	structcomplex.real=real;
	structcomplex.imaginary=imaginary;
}

