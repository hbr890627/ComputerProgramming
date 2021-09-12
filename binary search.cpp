#include <iostream>
using namespace std;

int binary(int a[], int value,int left,int right){
	if(left>right)
		cout<<"";
	int mid=(left+right)/2;
	if(a[mid]==value)
		cout<<value<<"位於第"<<mid+1<<"個";
	else if(a[mid]>value)
		binary(a, value, left, mid-1);
	else if(a[mid]<value)
		binary(a, value, mid+1, right);
	else
		cout<<"not found";
}


int main(){
	int a[]={1,2,3,4,5,6,41,8,9,10,11,12,13,14,15,16,17,18,21,20};
	int b;
	cin>>b;
	binary(a, b, 0, 19);	
}

