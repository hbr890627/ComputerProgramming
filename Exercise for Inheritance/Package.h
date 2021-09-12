#ifndef pack
#define pack

#include <string>
#include <iostream>
using namespace std;

class Package{
	friend ostream &operator<<( ostream &, const Package & );
	public:
		Package(string,string,string,string,int,string,string,string,string,int,double,double);
		double calculateCost() const;
	protected:
		string Sender_name;
		string Sender_address;
		string Sender_city;
		string Sender_state;
		int Sender_ZIP;
		
		string Recipient_name;
		string Recipient_address;
		string Recipient_city;
		string Recipient_state;
		int Recipient_ZIP;
		
		double weight;
		double CostPerOunce;
		
		static int mode;
};

int mode=1;
ostream &operator<<( ostream &output, const Package &p ){
	if (mode==1){
		output<<"Package "<<mode<<":\n\n"<<"Sender:\n"<<p.Sender_name<<"\n"<<p.Sender_address<<"\n"<<p.Sender_city<<", "<<p.Sender_state<<" "<<p.Sender_ZIP<<"\n\n"
			<<"Recipient:\n"<<p.Recipient_name<<"\n"<<p.Recipient_address<<"\n"<<p.Recipient_city<<", "<<p.Recipient_state<<" "<<p.Recipient_ZIP;
		mode++;
		return output;
	}else{
		output<<p.calculateCost()<<endl;
		return output;
	}
}

Package::Package(string Sn,string Sa,string Sc,string Ss,int SZ,string Rn,string Ra,string Rc,string Rs,int RZ,double w, double PerCost )
:Sender_name(Sn),
Sender_address(Sa),
Sender_city(Sc),
Sender_state(Ss),
Sender_ZIP(SZ),
Recipient_name(Rn),
Recipient_address(Ra),
Recipient_city(Rc),
Recipient_state(Rs),
Recipient_ZIP(RZ),
weight(w),
CostPerOunce(PerCost)
{}

double Package::calculateCost() const{
	return weight*CostPerOunce;
}
#endif
