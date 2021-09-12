#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;

class Date{
	friend ostream &operator<<(ostream &, const Date &);
	public:
		Date(int=1,int=2,int=1900);
		void setDate(int,int,int);
		int getMonth();
		bool leapYear(int);
	private:
		int month;
		int day;
		int year;
		static const int days[];
};

const int Date::days[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

ostream &operator<<( ostream &output, const Date &d ){
	output<<d.month<<"/"<<d.day<<"/"<<d.year;
	return output;
}

Date::Date(int m,int d,int y){
	setDate(m,d,y);
}

void Date::setDate(int m,int d,int y){
	month=(m>=1&&m<=12)?m:1;
	year=(y>=1900&&y<=2100)?y:1900;
	if(month==2&&leapYear(year)){
		day=(d>=1&&d<=29)?d:1;
	}else
		day=(d>=1&&d<=days[month])?d:1;
}

int Date::getMonth(){
	return month;	
}

bool Date::leapYear(int y){
	if(y%400==0||(y%100!=0&&y%4==0))
		return true;
	else
		return false;	
}


#endif
