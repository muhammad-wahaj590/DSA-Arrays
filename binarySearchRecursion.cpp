#include <iostream>
using namespace std;
int binarySearch(int arr[], int low, int high, int key){
//	base case
if(low>high){
	return -1;
}
int mid = low + (high-low)/2;
if(arr[mid]==key){
	return arr[mid];
}

//recursive relation
if(arr[mid<key]){
	return binarySearch(arr, mid+1, high, key);
}else{
	return binarySearch(arr, low, mid-1, key);
}
}
int main(){
	int arr[10] = {2,3,4,5,6,34,55,66,77,88};
	int size = 10;
	int key = 77;
	cout<<"key found or not found" <<binarySearch(arr, 0, 10, key);
	return 0;
}
