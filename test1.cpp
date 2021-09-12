#include <iostream>
#include <iomanip>
using namespace std;

void swap(int &a, int &b){
	int temp=a;
	a=b;
	b=temp;
}

int binary(int a[], int value, int start, int end){
	if(end>=start){
	int mid=(start+end)/2;
		if(a[mid]==value){
			cout<<value<<"is at"<<mid+1;
		}
		else if(a[mid]>value)
			binary(a,value,start,mid-1);
		else if(a[mid]<value)
			binary(a,value,mid+1,end);
	}
	else
		cout<<"not found";
}

int partition(int a[], int left, int right, int index){
	int value, newindex;
	value=a[index];
	newindex=left;
	swap(a[right], a[index]);
	for(int i=left;i<right;i++)
	{
		if(a[i]<value){
			swap(a[i],a[newindex]);
			newindex++;
		}
	}
	swap(a[right],a[newindex]);
	return newindex;
}

void quicksort(int a[], int left, int right){
	int index;
	int newindex;
	if(left>=right)
		return;
	index=left;
	newindex=partition(a, left, right, index);
	quicksort(a,left,newindex-1);
	quicksort(a,newindex+1,right);
}



int main(){
	const int arrS=20;
	int arr[arrS]={2,25,48,46,99,87,45,13,54,66,78,55,18,35,8,64,874,12,48,456};

	for (int i = 0; i < arrS; i++){
		cout<<setw(4)<<arr[i]<<' ';
	}
	cout<<endl;
	quicksort(arr, 0, arrS-1 );

	for (int i = 0; i < arrS; i++){
		cout<<setw(4)<<arr[i]<<' ';
	}
	cout<<endl;
	
	int search;
	int a=0;
	while(a==0){
		cin>>search;
		binary(arr,search,0,arrS-1);
	}
}
