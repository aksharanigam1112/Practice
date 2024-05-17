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

int burnTreeUtil(Node* root, Node* target, queue<Node*>& q) 
{ 
	if(root == NULL)  
		return 0; 
	
	if(root == target) 
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

	return -1; 
} 


// TC : O(N^2) & SC : O(N)
void burnTree(Node* root, Node* target) 
{ 
	queue<Node*> q; 
	
	burnTreeUtil(root, target, q); 
	int time = 0;
	
	while(!q.empty()) 
	{ 
        Node* temp = q.front(); 
        
        cout<<temp->data<<" ";

        if(temp->left != NULL)  
            q.push(temp->left); 
        
        if(temp->right != NULL)   
            q.push(temp->right);

        q.pop(); 
	    cout<<endl; 
	} 
}


/*----------------- NEWER APPROCH ---------------*/

// Using DFS

// TC : O(N) 	& 	SC : O(N) 
int burnTime(Node* root, Node* target, int level, int consider, map<int, vector<int>>&ans){
	if(root == NULL)
		return -1;

	if(consider == 1)
		ans[level].push_back(root->data);

	// 1. If we find the target node, then we know that we have to start from 1 for all the children of the sub-tree 
	// rooted at this node. In addition, we return 1, meaning that we found the target value.
	if(root == target) {
		ans[0].push_back(root->data);
		burnTime(root->left, target, 1, 1, ans);
		burnTime(root->right, target, 1, 1, ans);
		return 1;
	}

	// 2. Recursively call for left & right subtree from the current node. 
	// Only one of these recursive calls can return 1, 
	// as the target node can be present only in one of the subtrees
	int left = burnTime(root->left, target, level+1, consider, ans);

	int right = burnTime(root->right, target, level+1, consider, ans);


	// 3. If we get 1 from the left subtree, so we recursively call for right subtree 
	// (the max value for the left subtree is taken care of in step 1). 
	if(left != -1){
		ans[left].push_back(root->data);
		burnTime(root->right, target, left+1, 1, ans);
		return left+1;
	}

	// Conversely, if we get 1 from right subtree, we recursively call for left subtree
	if(right != -1) {
		ans[right].push_back(root->data);
		burnTime(root->left, target, right+1, 1, ans);
		return right+1;
	}

	return -1;
}

void burnTree2(Node* root, Node* target) {
	// stores the nodes burnt at each stage
	map<int, vector<int>> ans;
	burnTime(root, target, 0, 0, ans);

	for (auto it : ans){
        for (int ele : it.second)
            cout<<ele<<" ";
        
        cout<<endl;
    }

    cout<<"Total time to burn the tree : "<<ans.size()<<endl;
}



// Using BFS

void buildGraph(Node* node, Node* parent, map<Node*, vector<Node*>> &adjList) {
	
	if(node == NULL || adjList.find(node) != adjList.end())
		return;

	if(parent != NULL){
		adjList[node].push_back(parent);
		adjList[parent].push_back(node);
	}

	buildGraph(node->left, node, adjList);
	buildGraph(node->right, node, adjList);
	
}

void burnTree3(Node* root, Node* target) {
	if(root == NULL)
		return ;

	map<Node*, vector<Node*> > adjList;
	map<Node*,bool> visited;
	queue<Node*> q;
	int time = 0;
	
	buildGraph(root, NULL, adjList);

	if(adjList.find(target) == adjList.end())
		return;

	q.push(target);
	visited[target] = true;

	while(!q.empty()){
		int size = q.size();
 		time++;

 		// Nodes at same distance (connected)
        for (int i = 0; i < size; i++) {
            Node* node = q.front();
            q.pop();
            cout<<node->data <<" ";

            for (auto nbr : adjList[node]) {
                if (visited[nbr])
                    continue;
                
                visited[nbr] = true;
                q.push(nbr);
            }
        }
        cout << endl;
	}

	cout<<"Total time to burn the tree : "<<time<<endl;
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
	
	Node* targetNode = root->left->right->left->left; // 11 
	 
	cout<<"Nodes burnt using Recursion : "<<endl; 
	burnTree(root, targetNode);

	cout<<"\nNodes burnt using DFS : "<<endl;
	burnTree2(root, targetNode);

	cout<<"\nNodes burnt using BFS : "<<endl;
	burnTree3(root, targetNode);

	return 0;
} 
