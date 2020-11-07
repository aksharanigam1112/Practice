// Given a binary tree Split it into two subtrees 
// by removing 1 edge such that the product of the sums of the subtrees are maximized.
#include<iostream>
#include<climits>
using namespace std;
struct node
{
    int data;
    node *left, *right;
};

node * newNode(int data)
{
    node *n = new node;
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

int sum(node* root)
{
    if(root == NULL)
        return 0;
    int lv = sum(root->left);
    int rv = sum(root->right);
    return root->data + lv + rv ;
}

int search(node* root, int totalSum , int &prd)
{
    if(root==NULL)
        return 0 ;
    
    int lv = search(root->left, totalSum, prd);
    int rv = search(root->right, totalSum, prd);

    int sub = root->data + lv + rv;

    prd = max(prd, (totalSum-sub)*sub);
    return sub;
}

int maxPrd(node * root)
{
    int totalSum = sum(root);
    int prd = INT_MIN;
    search(root,totalSum,prd);
    return prd;
}

int main()
{
    node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    root->left->left = newNode(4);
    root->left->right = newNode(5);

    root->right->left = newNode(6);

    cout<<"Max Product : "<<maxPrd(root)<<endl;
}