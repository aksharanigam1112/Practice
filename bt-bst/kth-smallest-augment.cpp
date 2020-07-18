// Using techq of left children for any node (left-total-child.cpp)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data,leftcount,totalChild;
    node*left,*right;
};

node* newNode(int data)
{
    node* n = new node();
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    n->leftcount = 0;
    n->totalChild = 0;
    return n;
}

node* storeLeftChilCount(node*root)
{
    if(root==NULL)
        return NULL;

    node*  LV = storeLeftChilCount(root->left);
    node*  RV = storeLeftChilCount(root->right);

    root->leftcount = LV!=NULL ? LV->totalChild+1 : 0;
    root->totalChild = LV != NULL && RV != NULL ? LV->totalChild + RV->totalChild + 2 : 
                                               ( (LV!=NULL ? LV->totalChild+1 : 0 ) + (RV!=NULL ? RV->totalChild+1 : 0)) ;
    return root; 
}

int smallest(node*root , int k)
{
    node*LV = newNode(INT_MIN);
    node*RV = newNode(INT_MIN);
    
    if(root->leftcount+1==k)
        return root->data;
        
    if(root->leftcount>=k)
        LV->data = root->left!=NULL ? smallest(root->left,k) : root->data;
    if(root->leftcount<k)
        RV->data = root->right!=NULL ? smallest(root->right,k-root->leftcount-1) : root->data;
    
    if(LV->data != INT_MIN)
        return LV->data;
    if(RV->data != INT_MIN)
        return RV->data;
}

int main()
{
    node*root = newNode(40);
    root->left = newNode(20);
    root->right = newNode(55);
    
    root->left->left = newNode(12);
    root->left->right = newNode(35);

    root->right->left = newNode(45);
    root->right->right = newNode(75);

    root->left->left->left = newNode(8);
    root->left->left->right = newNode(15);
    root->left->right->right = newNode(38);

    root->right->left->right = newNode(50);
    root->right->right->left = newNode(60);

    root = storeLeftChilCount(root);

    int k=11;
  
    cout<<"Kth smallest element : "<<smallest(root,k)<<endl;
    
}