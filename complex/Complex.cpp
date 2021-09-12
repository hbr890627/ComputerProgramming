#include<iostream>
#include"Complex.h"
using namespace std;

Complex::Complex(double a, double b){
	setComplexNumber(a,b);
}
void Complex::setComplexNumber(double a, double b){
	realPart=a;
	imaginaryPart=b;
}	 
void Complex::printComplex(){
	cout<<"("<<realPart<<", "<<imaginaryPart<<")";
}
Complex Complex::add(Complex addend){
	Complex sum;
	sum.realPart= realPart+addend.realPart;
	sum.imaginaryPart= imaginaryPart+addend.imaginaryPart;
	return	sum;
}
Complex Complex::subtract(Complex subtraction){
	Complex difference;
	difference.realPart=realPart-subtraction.realPart;
	difference.imaginaryPart=imaginaryPart-subtraction.imaginaryPart;
	return difference;
}
