#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
using namespace std;

typedef struct 
{
    double real;
    double imaginary;
} complexstruct;

class Complex
{
 friend ostream &operator<<( ostream &, const Complex & );
 friend istream &operator>>( istream &, Complex & );
public:
    Complex( double = 0.0, double = 0.0 ); // constructor
    Complex add( const Complex & ) const; // addition
    Complex operator+( const Complex & ) const; // addition
    Complex operator-( const Complex & ) const; // subtraction
    void Setcomplex(double = 0.0, double = 0.0 );
    void print() const; // output
 private:
    complexstruct structcomplex; //structure data
};
#endif
// end class Complex
