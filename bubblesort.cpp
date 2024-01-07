#include <iostream>
#include <vector>
using namespace std;

void bribedQueue(vector<int>& queue){
	int n = queue.size();
	bool swapped;
	for(int i=0; i<n-1; i++){
		swapped=false;
		for(int j=0; j<n-i-1; j++){
			if(queue[j]>queue[j+1]){
				swap(queue[j], queue[j+1]);
			}
		}
		swapped=true;
		
		if (!swapped)
		break;
	}
	
}

int main(){
	int arr[] = {1,2,3,4,5,8,6,7};
	vector<int> queue(arr, arr + sizeof(arr) / sizeof(arr[0]));
	bribedQueue(queue);
	cout<<"original array: ";
	for(int num : queue){
		cout<<num<<" "<<endl;
	}
	return 0;
}
