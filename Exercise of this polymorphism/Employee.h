#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>
#include "Date.h"
using namespace std;

class Employee{	
	public:
		Employee(const string &,const string &,const string &,int,int,int );
		
		Date getBirthDate();

		virtual double earnings() const=0;
		virtual void print() const;
		
	private:
		string firstName;
		string lastName;
		string socialSecurityNumber;
		Date birthday;
};

Employee::Employee(const string &f,const string &l,const string &ssn,int m,int d,int y)
:firstName(f),
lastName(l),
socialSecurityNumber(ssn),
birthday(m,d,y)
{
	//birthday=Date(m,d,y);
}

Date Employee::getBirthDate(){
	return birthday;
}



void Employee::print() const{
	cout<<firstName<<' '<<lastName<<"\nsocial security number: "<<socialSecurityNumber
	<<"\nbirthday: "<<birthday;
}



#endif
