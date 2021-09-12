#include "CommissionEmployee.h"

class BasePlusCommissionEmployee:public CommissionEmployee{
	public:
		BasePlusCommissionEmployee(const string &,const string &,const string &,int,int,int,double=0.0,double=0.0,double=0.0);
		
		void setBaseSalary(double);
		double getBaseSalary() const;
			
		virtual double earnings() const;
		virtual void print() const;
	private:
		double baseSalary;
		
};

BasePlusCommissionEmployee::BasePlusCommissionEmployee(const string &f,const string &l,const string &ssn,int d,int m,int y,double gross,double rate,double base)
:CommissionEmployee(f,l,ssn,d,m,y,gross,rate),
baseSalary(base)
{}

void BasePlusCommissionEmployee::setBaseSalary(double salary){
	baseSalary=salary;
}

double BasePlusCommissionEmployee::getBaseSalary() const{
	return baseSalary;
}

double BasePlusCommissionEmployee::earnings() const{
	return baseSalary+CommissionEmployee::earnings();
}

void BasePlusCommissionEmployee::print() const{
	cout<<"base-salaried ";
	CommissionEmployee::print();
	cout<<"; base salary: "<<baseSalary;
}
