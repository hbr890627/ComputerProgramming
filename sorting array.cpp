#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main(){
	const int arrS=10;
	int data[arrS]={0};
	int insert;
	for (int i = 0; i < arrS; ++i)
	{
		data[i]=rand();
	}

	for (int i = 0; i < arrS; i++)
	{
		cout<<setw(4)<<data[i]<<' ';
	}
	for (int i = 0; i < arrS; i++)
	{
		insert=data[i];
		int move=i;
		while((move>0)&&(data[move-1]>insert)){
			data[move]=data[move-1];
			move--;
		}
	data[move]=insert;
	}
	cout<<endl;
	for (int i = 0; i < arrS; i++)
	{
		cout<<setw(4)<<data[i]<<' ';
	}
}
