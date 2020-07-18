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

void print(node*root)
{
    if(root==NULL)
        return;
    print(root->left);
    print(root->right);
    cout<<root->data<<" "<<root->leftcount<<" "<<root->totalChild<<endl;
}


int main()
{
    node*root = newNode(40);
    root->left = newNode(20);
    root->right = newNode(55);
    
    root->left->left = newNode(12);
    root->left->right = newNode(35);

    root->left->left->left = newNode(8);
    root->left->left->right = newNode(15);

    root = storeLeftChilCount(root);
    cout<<"Data , LeftChildren , TotalChildren"<<endl;
    print(root);
}