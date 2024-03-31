#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class MaxHeap {

public:
	vector<int> arr;
	int size;

	MaxHeap() {
		size = 0;
	}

	void print() {
		for(int ele : arr){
			cout<<ele<<" ";
		}
		cout<<"\n\n";
	}

	void percolateUp(int index) {
		if(index == 0)
			return;

		int parent = index%2==0 ? index/2-1 : index/2;

		if(arr[parent] < arr[index]) {
			swap(arr[index], arr[parent]);
			percolateUp(parent);
		}

		/** ITERATIVE APPROACH
		while(index > 0) {
			int parent = index%2 == 0 ? (index/2)-1 : index/2;

			if(arr[parent] < arr[index]) {
				swap(arr[index], arr[parent]);
				index = parent;
			}
			else
				return;
		}*/
	}

	void insert(int val) {
		// 1. Push element to the last
		arr.push_back(val);
		// 2. Update the size
		size = arr.size();
		// 3. Move the node to its right position
		percolateUp(size-1);
	}

	void heapify(int index) {

		if(index >= size)
			return;

		int leftNode = 2*index+1, rightNode = 2*index+2;

		int pos = arr[leftNode] > arr[rightNode] ? leftNode : rightNode;

		swap(arr[index], arr[pos]);
		heapify(pos);

		/** ITERATIVE APPROACH
		while(index < size) {
			int leftNode = 2*index+1, rightNode = 2*index+2;

			int pos = arr[leftNode] > arr[rightNode] ? leftNode : rightNode;

			swap(arr[index], arr[pos]);
			index = pos;
		}*/
	}

	int removeTop() {
		if(size == 0)
			return -1;

		int topEle = arr[0];
		
		// 1. Swap the first & last nodes 
		swap(arr[0], arr[size-1]);
		// 2. Reduce the size
		size--;
		// 3. heapify i.e propagate root node to its actual position
		heapify(0);

		return topEle;
	}
};

int main() {

	MaxHeap h = MaxHeap();

	h.insert(60);
	h.insert(50);
	h.insert(40);
	h.insert(30);
	h.print();

	h.insert(55);
	h.insert(20);
	h.print();

	h.insert(70);
	h.print();

	cout<<"Max element : "<<h.removeTop()<<endl;
	h.print();

	cout<<"Max element : "<<h.removeTop()<<endl;
	h.print();
}
