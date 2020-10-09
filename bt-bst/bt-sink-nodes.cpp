// Given a BT containing many zero nodes, sink nodes having zero value to the bottom 
// of the subtree rooted at that node. 
#include <iostream>
using namespace std;
struct node
{
	int data;
	node *left, *right;
};

node* newNode(int data)
{
    node* n = new node;
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

void print(node *root)
{
	if (root == NULL)
		return;

    cout<<root->data<<" ";
	print(root->left);
	print(root->right);
}

void sink(node *root)
{
	if (root == NULL)
		return;
    
    if (root->left != NULL && root->left->data != 0)
	{
		swap(root->data, root->left->data);
        sink(root->left);
	}
	else if (root->right != NULL && root->right->data != 0)
	{
		swap(root->data, root->right->data);
        sink(root->right);
	}
}

void sinkNodes(node*root)
{
	if (root == NULL)
		return;

	sinkNodes(root->left);
	sinkNodes(root->right);

	if (root->data == 0)
		sink(root);
}

int main()
{
	node* root = newNode(0);
	root->left = newNode(1);
	root->right = newNode(0);

	root->right->left = newNode(0);
	root->right->right = newNode(2);
	
    root->right->left->left = newNode(3);
	root->right->left->right = newNode(4);

    cout<<"Given Binary Tree : ";
    print(root);
    cout<<endl;

	sinkNodes(root);
    cout<<"Modified Binary Tree : ";
	print(root);
    cout<<endl;
}