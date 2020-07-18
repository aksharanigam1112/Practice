// Given the root node of a binary search tree, 
// return the sum of values of all nodes with value between L and R (inclusive).
#include<iostream>
using namespace std;

struct node
{
    int data;
    node*left,*right;
};

node* newNode(int data)
{
    node* n = new node;
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

void sumRange(node*root, int l, int r, int &sumSoFar)
{
    if(root==NULL)
        return;
    sumRange(root->left,l,r,sumSoFar);
    if(root->data>=l && root->data<=r)
        sumSoFar += root->data;
    sumRange(root->right,l,r,sumSoFar);
}

int main()
{
    node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(15);
    root->left->left = newNode(3);
    root->left->right = newNode(7);
    root->right->right = newNode(18);

    int L = 7, R = 15,sum=0;
    sumRange(root,L,R,sum);
    cout<<"Sum  : "<<sum<<endl;
}