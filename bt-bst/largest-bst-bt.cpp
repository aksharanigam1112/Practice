#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left,*right;
};

class returnType
{
    public:
    bool isBST;
    int Rmin, Lmax, size;
};

node* newNode(int key) 
{ 
    node *temp = new node; 
    temp->data = key; 
    temp->left = temp->right = NULL; 
    return temp; 
}

returnType largestBst(node*root)
{
    returnType rt;
    if(root==NULL)
    {
        rt.isBST = true;
        rt.Lmax = INT_MIN;
        rt.Rmin = INT_MAX;
        rt.size=0;
        return rt;
    }

    returnType LV = largestBst(root->left);
    returnType RV = largestBst(root->right);

    if(LV.isBST && RV.isBST && LV.Lmax <= root->data && RV.Rmin > root->data)
    {
        rt.isBST = true;
        rt.Lmax = max(RV.Lmax,root->data);
        rt.Rmin = min(LV.Rmin,root->data);
        rt.size = LV.size + RV.size +1;
        return rt;
    }
    rt.isBST = false;
    rt.Lmax = INT_MIN;
    rt.Rmin = INT_MAX;
    rt.size = max(LV.size , RV.size);
    return rt;
}

int main()
{
    node*root = newNode(10);
    root->left  = newNode(15);
    root->right = newNode(21);

    root->left->left = newNode(7);
    root->left->right = newNode(28);
    root->left->left->left = newNode(31);

    root->right->left = newNode(7);
    root->right->right = newNode(50);

    root->right->left->left = newNode(3);
    root->right->left->right = newNode(15);

    root->right->right->left = newNode(45);
    root->right->right->right = newNode(67);

    returnType r = largestBst(root);
    cout<<"The size is : "<<r.size<<endl;
}