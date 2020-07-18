#include<iostream>
#include <bits/stdc++.h> 
using namespace std; 

struct Node 
{ 
	int data; 
	Node *left, *right; 
}; 

Node* newNode(int data) 
{ 
	Node* temp = new Node; 
	temp->data = data; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

int burnTreeUtil(Node* root, int target, queue<Node*>& q) 
{ 
	if(root == NULL)  
		return 0; 
	
	if(root->data == target) 
	{ 
		cout<<root->data<<endl; 
		if(root->left != NULL) 
			q.push(root->left); 
		
		if(root->right != NULL)
			q.push(root->right); 

		return 1; 
	} 
	
	int a = burnTreeUtil(root->left, target, q); 
		
	if(a == 1) 
	{ 
		int qsize = q.size(); 
		
		while(qsize--) 
		{ 
			Node* temp = q.front(); 
			
			cout<<temp->data<<" , "; 
			q.pop(); 
			
			if(temp->left != NULL) 
				q.push(temp->left); 
				
			if(temp->right != NULL) 
					q.push(temp->right); 
		} 
			
		if(root->right != NULL) 
			q.push(root->right); 

		cout<<root->data<<endl; 
			
		return 1; 
	} 
	
	int b = burnTreeUtil(root->right, target, q); 
	
	if(b == 1) 
	{ 
		int qsize = q.size(); 
		
        while(qsize--) 
		{ 
			Node* temp = q.front(); 
				
			cout<<temp->data<<" , "; 
			q.pop(); 
				
			if(temp->left != NULL) 
				q.push(temp->left); 
				
			if(temp->right != NULL) 
				q.push(temp->right); 
		} 
		
		if(root->left != NULL) 
			q.push(root->left); 
	
		cout<<root->data<<endl; 
		return 1; 
	} 
} 

void burnTree(Node* root, int target) 
{ 
	queue<Node*> q; 
	
	burnTreeUtil(root, target, q); 
	
	while(!q.empty()) 
	{ 
	    int qSize = q.size(); 
        while(qSize > 0) 
        { 
            Node* temp = q.front(); 
            
            cout<<temp->data<<" "; 
            if(temp->left != NULL)  
                q.push(temp->left); 
            
            if(temp->right != NULL)   
                q.push(temp->right); 
            
        // if(q.size()!=1) 
        // cout << " , "; 

            q.pop(); 
            qSize--; 
	    } 
	    cout<<endl; 
	} 
} 

int main() 
{ 
	Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->left->left->left = newNode(8); 
    root->left->right->left = newNode(9); 
    root->left->right->right = newNode(10); 
    root->left->right->left->left = newNode(11); 
	int targetNode = 11; 
	 
	burnTree(root, targetNode); 

	return 0; 
} 
