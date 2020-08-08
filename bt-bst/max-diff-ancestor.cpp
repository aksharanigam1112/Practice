// For a pair of nodes (a,b) where a is the ancestor of b
// Find the maximum diff between any such pair
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node*left,*right;
};

struct rt
{
    int minVal=-1,maxDiff=0;
};

node* newNode(int data)
{
    node* n = new node;
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

rt findMaxDiff(node*root)
{
    rt obj;
    if(root==NULL)
        return obj;

    rt LV = findMaxDiff(root->left);
    rt RV = findMaxDiff(root->right);

    int m1;

    if(root->left==NULL && root->right==NULL)
        m1 = root->data;
    else if(root->left==NULL)
        m1 = RV.minVal;
    else if(root->right==NULL)
        m1 = LV.minVal;
    else
        m1 = min(LV.minVal,RV.minVal);
    
    
    int m2 = max(LV.maxDiff,RV.maxDiff);

    obj.maxDiff = max(abs(root->data-m1),m2);
    obj.minVal = min(m1,root->data);
    return obj;
}

int main()
{
    node* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(7);

    root->left->left = newNode(1);
    root->right->left = newNode(3);
    root->right->right = newNode(16);

    root->left->left->left = newNode(3);
    root->left->left->right = newNode(8);
    root->right->left->left = newNode(6);
    root->right->left->right = newNode(2);
    root->right->right->right = newNode(5);

    rt ans ;
    ans = findMaxDiff(root);
    cout<<"Max diff : "<<ans.maxDiff<<endl;
}