#ifndef COM_H
#define COM_H

class Complex
{
public:
	Complex(double=0, double=0);
	void setComplexNumber(double, double);
	void printComplex();
	Complex add(Complex);
	Complex subtract(Complex);
private:
	double realPart;
	double imaginaryPart;
};

#endif
