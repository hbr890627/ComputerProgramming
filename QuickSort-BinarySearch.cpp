#include <iostream>
#include <iomanip>
using namespace std;

void swap(int &a, int &b ){
	int temp=a;
	a=b;
	b=temp;
}

void binary(int a[], int value,int left,int right){
	if(left<=right){ 
		int mid=(left+right)/2;
		if(a[mid]==value)
			cout<<value<<"is at"<<mid+1<<"\n\n";
		else if(a[mid]>value)
			binary(a, value, left, mid-1);
		else if(a[mid]<value)
			binary(a, value, mid+1, right);
	}
	else
		cout<<"not found\n\n";
}
int  Partition(int a[], int left, int right, int Index){
	int Value=a[Index];
	swap(a[Index],a[right]);
	int storeIndex = left ;
	for(int i=left; i<right; i++){
		if(a[i]<Value){
			swap(a[storeIndex],a[i]);
			storeIndex++;
		}
	}
	swap(a[right], a[storeIndex]);
	return storeIndex;
}
void QuickSort(int a[], int first, int last){
	int Index, NewIndex;
	if(first>=last)
		return;
	Index=first;
	NewIndex=Partition(a,first,last,Index);		
	QuickSort(a, first, NewIndex-1);
	QuickSort(a, NewIndex+1, last);
}


int main(){
	const int arrS=20;
	int arr[arrS]={2,25,48,46,99,87,45,13,54,66,78,55,18,35,8,64,874,12,48,456};

	for (int i = 0; i < arrS; i++){
		cout<<setw(4)<<arr[i]<<' ';
	}
	cout<<endl;
	QuickSort(arr, 0, arrS-1 );

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
