#include "Package.h"

class TwoDayPackage:public Package{
	friend ostream &operator<<( ostream &, const TwoDayPackage & );
	public:
		TwoDayPackage(string,string,string,string,int,string,string,string,string,int,double,double,double);
		double calculateCost() const;
	private:
		double flat_fee;
};

ostream &operator<<( ostream &output, const TwoDayPackage &p ){
	if (mode==2){
		output<<"Package "<<mode<<":\n\n"<<"Sender:\n"<<p.Sender_name<<"\n"<<p.Sender_address<<"\n"<<p.Sender_city<<", "<<p.Sender_state<<" "<<p.Sender_ZIP<<"\n\n"
			<<"Recipient:\n"<<p.Recipient_name<<"\n"<<p.Recipient_address<<"\n"<<p.Recipient_city<<", "<<p.Recipient_state<<" "<<p.Recipient_ZIP;
		mode++;
		return output;
	}else{
		output<<p.calculateCost()<<endl;
		return output;
	}
}

TwoDayPackage::TwoDayPackage(string Sn,string Sa,string Sc,string Ss,int SZ,string Rn,string Ra,string Rc,string Rs,int RZ,double w,double PerCost,double fee)
:Package(Sn,Sa,Sc,Ss,SZ,Rn,Ra,Rc,Rs,RZ,w,PerCost),
flat_fee(fee)
{}

double TwoDayPackage::calculateCost() const{
	return (flat_fee+Package::calculateCost());
}

