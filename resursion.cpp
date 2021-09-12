#include<iostream>
using namespace std;

long long fibonacci(long long);

int main(){
	for(int counter=0; counter<=80; counter++){
		cout<<"fibonacci ( "<<counter<<" ) = "<<fibonacci(counter)<<endl;
	}
}

long long fibonacci(long long a){
	if ((a==0)||(a==1))
		return a;
	else
		return fibonacci(a-1)+fibonacci(a-2);
}

