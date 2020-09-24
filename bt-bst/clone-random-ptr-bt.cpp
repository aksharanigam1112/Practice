// Clone a Binry Tree with Random Pointers
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node*left,*right,*random;
};

node* newNode(int data)
{
    node*n = new node;
    n->data = data;
    n->left = n->random = n->right = NULL;
    return n;
}

void preorder(node*root)
{
    if (root == NULL)
		return;

	cout<<root->data<<" --> (";
	(root->left) ? cout<<root->left->data<< ", " : cout<<"X, ";
	(root->right) ? cout<<root->right->data<<", " : cout<<"X, ";
    (root->random) ? cout<<root->random->data<<")\n" : cout<<"X)\n";

	preorder(root->left);
	preorder(root->right);
}

void updateRandomPointers(node* root, map<node*, node*> &map)
{
	if(map[root] == NULL)
		return;

	map[root]->random = map[root->random];

	updateRandomPointers(root->left, map);
	updateRandomPointers(root->right, map);
}

node* cloneLeftRightPointers(node* root, map<node*, node*> &map)
{
	if(root == NULL)
		return NULL;

	map[root] = newNode(root->data);

	map[root]->left = cloneLeftRightPointers(root->left, map);
	map[root]->right = cloneLeftRightPointers(root->right, map);
    
    return map[root];
}

// TC : O(N)
node* cloneBT(node* root)
{
	map<node*, node*> map;

	cloneLeftRightPointers(root, map);
    updateRandomPointers(root, map);
    
    return map[root];
}


int main()
{
    node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);

	root->random = root->right->left->random;
	root->left->left->random = root->right;
	root->left->right->random = root;
	root->right->left->random = root->left->left;
	root->random = root->left;

    cout<<"Original Tree : "<<endl;
    preorder(root);
    cout<<endl;

    node* clone = cloneBT(root);
    cout<<"Cloned Tree : "<<endl;
    preorder(clone);
    // cout<<endl;
}