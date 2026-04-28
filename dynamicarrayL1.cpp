/*Store them in a dynamic array
Print them
Print their sum
Print the largest element*/

#include<iostream>
using namespace std;
class dynamicArray{
	int* arr;
	int size;
	int capacity;
	
	public:
	dynamicArray(){
		arr = new int[capacity];  
		capacity = 1;
		size = 0;
	}
	void addToDynamicArr(int value){
		if(size==capacity){
			capacity *= 2;
			int* newArr = new int[capacity]; //new array is made of  doubled size
			
		for(int i = 0; i<size; i++){
			newArr[i]=arr[i];
		}
		delete[] arr;
		arr = newArr;
		}
		arr[size]=value;
		size++;
		
	}
          
		  
		  void displayArray(){
		  	for(int i = 0; i<size; i++){
		  		cout<<arr[i]<<" ";
			  }
		  }
};
int main(){
    dynamicArray d;
	
	cout<<"dynamic Array:"<<"\n"<<"insert new member"<<endl;
	d.addToDynamicArr(5);
	d.addToDynamicArr(7);
	d.addToDynamicArr(9);
	d.displayArray();
	return 0;
}
