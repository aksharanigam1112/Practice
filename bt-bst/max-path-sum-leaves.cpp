#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node*left,*right;
};
node* newNode(int key) 
{ 
    node *temp = new node; 
    temp->data = key; 
    temp->left = temp->right = NULL; 
    return temp; 
}

// TC : O(N^2)

// finding max path sum from root to any leaf node
int maxPath(node*root)
{
    if(root==NULL)
        return 0;
    return root->data +max( maxPath(root->left) , maxPath(root->right));
}

// finding the max path sum from root to its parents
int getMaxSum(node * root)
{
    if(root==NULL)
        return 0;

    int LV = root->left!=NULL ? maxPath(root->left) : INT_MIN;
    int RV = root->right!=NULL ? maxPath(root->right) : INT_MIN;
    int CV = LV+RV+root->data;
    
    int leftMaxSum = getMaxSum(root->left);
    int rightMaxSum = getMaxSum(root->right);
    
    return max(CV,max(leftMaxSum,rightMaxSum));
}


// TC : O(N)
int getMaxSum2(node *root, int &res) 
{ 
	if (root==NULL) 
        return 0; 

	if(root->left==NULL && root->right==NULL) 
        return root->data; 

	int ls = getMaxSum2(root->left, res); 
	int rs = getMaxSum2(root->right, res); 

	if (root->left && root->right) 
		res = max(res, ls + rs + root->data); 

	return max(ls, rs) + root->data;
} 


int main()
{
    node *root = newNode(-15); 
	root->left = newNode(5); 
	root->right = newNode(6); 
	root->left->left = newNode(-8); 
	root->left->right = newNode(1); 
	root->left->left->left = newNode(2); 
	root->left->left->right = newNode(6); 
	root->right->left = newNode(3); 
	root->right->right = newNode(9); 
	root->right->right->right= newNode(0); 
	root->right->right->right->left= newNode(4); 
	root->right->right->right->right= newNode(-1); 
	root->right->right->right->right->left= newNode(10); 

    int res = INT_MIN; 
	getMaxSum2(root, res);
    cout<<res<<endl;
}
