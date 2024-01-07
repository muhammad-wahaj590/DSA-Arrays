#include <iostream>
#include <queue>
using namespace std;

class heap{
	public:
		int arr[100];       //maximum array main 100 values pass ho saktin
		int size;
		
//	constructor
	heap(){
		arr[0] = -1;        // 0 index ko include nhi karwana chahty
		size = 0;           // size initially 0 hai
	}
	void insert(int val){
		size = size + 1;     //sab se pehlay size ko barha dia 
		int index = size;    //is size main index dalna chata
		arr[index] = val;    //value index main add kardi
		
		while(index > 1){
			int parent = index/2;
			
			if(arr[parent] < arr[index]){      //agar parent chota hai us new value se jo abhi add hoi
				swap(arr[parent], arr[index]); //to parent ko us value k sath swap karwa do
				index = parent;                //or values set kardo dono ki ek dosry ki jagah
			}
			else{     
				return;
			}
		}
	}
	
	void delete_from_heap(){
//		base case
		if(size == 0){                      //jab kuch delete karne k liye hi na ho
			cout<<"Nothing to delete"<<endl;
			return;
		}
		
//		step:1 put last e;lement into first element
		arr[1] = arr[size];                 //value ko rot node pe laye
//		step:2 remove last element
		size--;                             //size decrement karwaya
		
//		step:3 take root node to its correct position 
		int i = 1;                        //root node ki index 1 hai
		while(i<size){                    //or jab tak size 1 se bara hai chalta rahy
			int leftIndex = 2*i;          //formula logic for left index
			int rightIndex = 2*i+1;       //formula logic for right index
			
			if(leftIndex < size && arr[i] < arr[leftIndex]){       
				swap(arr[i], arr[leftIndex]);      //agar 55 60 hai to 60 55 karden ge
				i = leftIndex;
			}
			else if(rightIndex < size && arr[i] < arr[rightIndex]){
				swap(arr[i], arr[rightIndex]);
				i = rightIndex;
			}
			else{
				return;            //already set the correct position
			}
		}
	}
	//for max
	//max heap main array ki indexing <= n hogi kyon k max number le rahy
	void heapify(int arr[], int n, int i){
		int largest = i;                   //isko sahi jagah pr le kar jana
		int leftIndex = 2*i;
		int rightIndex = 2*i+1;
		
		if(leftIndex <= n && arr[largest] < arr[leftIndex]){  //agar leftindex total(n) se hiota hai or or largest chota hai left se to swipe
			largest = leftIndex;
		}
		if(rightIndex <= n && arr[largest] < arr[rightIndex]){
			largest = rightIndex;
		}
		//agar largest update ho gaya to woh i ki jagah to nhi hoga to check karo k woh update hoa ya nhi 
		if(largest!=i){
			swap(arr[largest], arr[i]);
//			then further or check karna k woh sahi jagah pohancha ya nhi to 
			heapify(arr, n, largest);    //to usy sahi jagah pohnacha do largest ko 
		}
		
	}
//	for min (sirf values largest ki jagah smallest rakhi hain)
//min heap main array ki indexing < n hogi kyon k min number le rahy
	void minHeapify(int arr[], int n, int i){
		int smallest = i;
		int leftIndex = 2*i + 1;
		int rightIndex = 2*i + 2;
		
		if(leftIndex < n && arr[smallest] > arr[leftIndex]){
			smallest = leftIndex;
		}
		if(rightIndex < n && arr[smallest] > arr[rightIndex]){
			smallest = rightIndex;
		}
		
		if(smallest!=i){
			swap(arr[i], arr[smallest]);    // is line maion i mat;lab bari value ko swap kar small choti value se
			minHeapify(arr, n, smallest);
		}
	}
	
	void heapSort(int arr[], int n){
		int size = n;    
		while(size > 1){
//			step: 1
			swap(arr[size], arr[1]);
//			step: 2
			size--;
//			step: 3
			heapify(arr, size, 1);
		}
	}
	void print(){
		for(int i=1; i<=size; i++){
			cout << arr[i] <<" ";
		}
		cout<<endl;
	}
};

int main(){
	heap h;
	h.insert(50);
	h.insert(55);
	h.insert(53);
	h.insert(52);
	h.insert(54);
	h.print();
	cout<<"deleting the node ";
	h.delete_from_heap();
	h.print();
	//max heap
	int arr[6] = {-1, 54, 53, 55, 52, 50};
	int n = 5;
//	heap creation  and max heapify code
	for(int i = n/2; i>0; i--) {
		h.heapify(arr, n, i);
	}
	cout <<"Printing the array for max heapify"<<endl;
	for(int i=1; i<=n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	cout << "---------------------------------------------"<<endl;	
	
	//heap sorted code   (min heap or heap sorted ek hi cheez hoi almost)
	h.heapSort(arr, n);
	cout <<"Printing sorted array"<<endl;
	for(int i=1; i<=n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	//min heap code	
	cout << "---------------------------------------------"<<endl;
	cout <<"min heapify"<<endl;
	for(int i = (n/2)-1; i>=0; i--){
		h.minHeapify(arr, n, i);
	}
	cout<<"Printing the array for min heapify"<<endl;
	for(int i=1; i<=n; i++){
		cout<<arr[i]<<" ";
	}
	cout <<endl;
	
	cout << "---------------------------------------------"<<endl;
//	max heap priority queue
	priority_queue<int> pq;
	pq.push(4);
	pq.push(2);
	pq.push(7);
	pq.push(1);
	
	cout<<"element at top " <<pq.top()<<endl;
	pq.pop();
	cout<<"element at top "<<pq.top()<<endl;
	cout<<"size is " << pq.size()<<endl;
	if(pq.empty()){
		cout<<"pq is empty"<<endl;
	}else{
		cout<<"pq is not empty";
	}
	cout<<endl;
	
	cout << "---------------------------------------------"<<endl;
	
	//complete binary tree main child kese nikalty k kitny hain in pooray tree main is formula se (n+1)/2
	
//	min heap priority queue
	priority_queue<int, vector<int>, greater<int> > minheap;    //vector(is se element heap ban saken) greater(compare k liye taky min heap ban saky)
	minheap.push(4);
	minheap.push(2);
	minheap.push(7);
	minheap.push(1);
	
	cout<<"element at top " <<minheap.top()<<endl;
	minheap.pop();
	cout<<"element at top "<<minheap.top()<<endl;
	cout<<"size is "<<minheap.size()<<endl;
	if(minheap.empty()){
		cout<<"minheap is empty"<<endl;
	}else{
		cout<<"minheap is not empty";
	}
	return 0;
}
