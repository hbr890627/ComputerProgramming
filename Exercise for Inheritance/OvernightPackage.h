#include "Package.h"

class OvernightPackage:public Package{
	friend ostream &operator<<( ostream &, const OvernightPackage & );
	public:
		OvernightPackage(string,string,string,string,int,string,string,string,string,int,double,double,double);
		double calculateCost() const;
	private:
		double AdditionalFeePerOunce;	
};

ostream &operator<<( ostream &output, const OvernightPackage &p ){
	if (mode==3){
		output<<"Package "<<mode<<":\n\n"<<"Sender:\n"<<p.Sender_name<<"\n"<<p.Sender_address<<"\n"<<p.Sender_city<<", "<<p.Sender_state<<" "<<p.Sender_ZIP<<"\n\n"
			<<"Recipient:\n"<<p.Recipient_name<<"\n"<<p.Recipient_address<<"\n"<<p.Recipient_city<<", "<<p.Recipient_state<<" "<<p.Recipient_ZIP;
		mode++;
		return output;
	}else{
		output<<p.calculateCost()<<endl;
		return output;
	}
}

OvernightPackage::OvernightPackage(string Sn,string Sa,string Sc,string Ss,int SZ,string Rn,string Ra,string Rc,string Rs,int RZ,double w,double PerCost,double addition)
:Package(Sn,Sa,Sc,Ss,SZ,Rn,Ra,Rc,Rs,RZ,w,PerCost),
AdditionalFeePerOunce(addition)
{}

double OvernightPackage::calculateCost() const{
	return weight*(CostPerOunce+AdditionalFeePerOunce);
}
