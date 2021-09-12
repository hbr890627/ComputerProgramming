#include<iostream>
#include<time.h>
using namespace std;

unsigned long fibo_recur(unsigned long);
unsigned long fibo_iter(unsigned long);

int main(){
	int startA, endA, startB, endB;
	
	startA=clock();
	for(int i=1; i<=100000; i++){
		fibo_iter(i);
	}
	endA=clock();
	double timeA=(double)(endA-startA)/CLOCKS_PER_SEC;
	
	startB=clock();
	for(int i=1; i<=100000; i++){
		for(int i=0; i<=10; i++){
			cout<<"fibonacci ( "<<i<<" ) = "<<fibo_recur(i)<<endl;
		}
	}
	endB=clock();
	double timeB=(double)(endB-startB)/CLOCKS_PER_SEC;
	
	cout<<"iteration花費時間"<<timeA<<endl;
	cout<<"recursion花費時間"<<timeB<<endl;	
}

unsigned long fibo_recur(unsigned long a){
	if ((a==0)||(a==1))
		return a;
	else
		return fibo_recur(a-1)+fibo_recur(a-2);
}

unsigned long fibo_iter(unsigned long a){
	unsigned long a1=0;
	unsigned long a2=1;
	unsigned long a3;
	cout<<"fibonacci ( "<<0<<" ) = "<<a1<<endl;
	cout<<"fibonacci ( "<<1<<" ) = "<<a2<<endl;
	for(int i=2; i<=10; i++){
		a3=a1+a2;
		cout<<"fibonacci ( "<<i<<" ) = "<<a3<<endl;
		a1=a2;
		a2=a3;
	}
}


