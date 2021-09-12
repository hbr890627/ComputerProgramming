#ifndef CEMPLOYEE_H
#define CEMPLOYEE_H

#include "Employee.h"

class CommissionEmployee:public Employee{
	public:
		CommissionEmployee(const string &,const string &,const string &,int,int,int,double=0.0,double=0.0);

		virtual double earnings() const;
		virtual void print() const;			
	private:
		double grossSales;
		double commissionRate;
};

CommissionEmployee::CommissionEmployee(const string &f,const string &l,const string &ssn,int d,int m,int y,double sales,double rate)
:Employee(f,l,ssn,d,m,y),
grossSales(sales),
commissionRate(rate)
{}

double CommissionEmployee::earnings() const{
	return grossSales*commissionRate;
}

void CommissionEmployee::print() const{
	cout<<"commission employee: ";
	Employee::print();
	cout<<"\ngross sales: "<<grossSales<<"; commission rate: "<<commissionRate;
}

#endif
