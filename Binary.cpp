#include <iostream>
#include <cstdio>
using namespace std;

int bisearch(int arr[], int l, int r, int value){ 
	int mid;
	if (l<r)
	{
		mid = (l+r)/2;
			
		if (arr[mid] = value) 
			return mid; 
		else if (arr[mid] < value) 
			bisearch(arr, mid+1, r, value);
		else
			bisearch(arr, l, mid+1, value);
	}
	return mid;
}

int main()
{
	int arr[] = {2,8,21,36,69,77,89};
	cout<<"It is: "<<bisearch(arr, 0, 6, 77)<<endl;
} 
