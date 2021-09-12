#include "Employee.h"

class SalariedEmployee:public Employee{
	public:
		SalariedEmployee(const string &,const string &,const string &,int,int,int,double=0.0);
		
		virtual double earnings() const;
		virtual void print() const;
	private:
		double weeklySalary;
};

SalariedEmployee::SalariedEmployee(const string &f,const string &l,const string &ssn,int d,int m,int y,double salary)
:Employee(f,l,ssn,d,m,y)
{
	weeklySalary=salary;
}

double SalariedEmployee::earnings() const{
	return weeklySalary;
}

void SalariedEmployee::print() const{
	cout<<"salaried employee: ";
	Employee::print();
	cout<<"\nweekly salary: "<<weeklySalary;
}
