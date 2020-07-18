#include<iostream>
#include <bits/stdc++.h> 
using namespace std; 
struct Item; 

struct Node 
{ 
	int val; 
	Node *next; 
	Item *itemPtr; 
}; 

struct Item 
{ 
	Node *hd, *tl; 
}; 

class ListSet 
{ 
    private: 
        unordered_map<int, Node *> nodeAddress; 

    public: 
        void makeset(int a); 
        Item* find(int key); 
        void Union(Item *i1, Item *i2); 
}; 

// To make a set with one object 
// with its representative 
void ListSet::makeset(int a) 
{ 
	Item *newSet = new Item; 
    newSet->hd = new Node; 
    
    newSet->tl = newSet->hd; 
	nodeAddress[a] = newSet->hd; 

	newSet->hd->val = a; 
	newSet->hd->itemPtr = newSet; 
	newSet->hd->next = NULL; 
} 

Item *ListSet::find(int key) 
{ 
	Node *ptr = nodeAddress[key]; 
	return (ptr->itemPtr); 
} 

void ListSet::Union(Item *set1, Item *set2) 
{ 
	Node *cur = set2->hd; 
	while (cur != 0) 
	{ 
		cur->itemPtr = set1; 
		cur = cur->next; 
	} 

	(set1->tl)->next = set2->hd; 
	set1->tl = set2->tl; 

	delete set2; 
} 

int main() 
{ 
	ListSet a; 
	a.makeset(1); 
	a.makeset(2); 
	a.makeset(3); 
	a.makeset(4); 

	cout << "find(1): " << a.find(1) << endl; 
	cout << "find(2): "<< a.find(2) << endl; 
	cout << "find(3): "<< a.find(3) << endl; 
	cout << "find(4): "<< a.find(4) << endl ; 
	cout << "Union(3,4) \n"; 

	a.Union(a.find(3), a.find(4)); 

	cout << "find(3): "<< a.find(3) << endl; 
	cout << "find(4): "<< a.find(4) << endl; 
	return 0; 
} 
