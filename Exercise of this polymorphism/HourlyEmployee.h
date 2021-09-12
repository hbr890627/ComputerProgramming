#include "Employee.h"

class HourlyEmployee:public Employee{
	public:
		HourlyEmployee(const string &,const string &,const string &,int,int,int,double=0.0,double=0.0);
		virtual double earnings() const;
		virtual void print() const;	
	private:
		double wage;
		double hours;
};

HourlyEmployee::HourlyEmployee(const string &f,const string &l,const string &ssn,int d,int m,int y,double hw,double hh)
:Employee(f,l,ssn,d,m,y)
{
	wage=hw;
	hours=hh;
}

double HourlyEmployee::earnings() const{
	if(hours<40)
		return wage*hours;
	else
		return 40*wage+((hours-40)*wage*1.5);
}

void HourlyEmployee::print() const{
	cout<<"salaried employee: ";
	Employee::print();
	cout<<"\nhourly salary: "<<wage<<"; hours worked: "<<hours;
}
