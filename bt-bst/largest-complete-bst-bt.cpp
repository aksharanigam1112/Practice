// On moving from left to right all left children should be present

// LH = RH ; Left ==> Full && Right ==> Complete  =====> Complete
// LH = RH+1 ; Left ==> Complete && Right ==> Full  =====> Complete

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
    bool isCBT, isfull;
    int height, size;
    node*head;
};

node* newNode(int key) 
{ 
    node *temp = new node; 
    temp->data = key; 
    temp->left = temp->right = NULL; 
    return temp; 
}

returnType largestCBT(node*root)
{
    returnType rt;
    if(root==NULL)
    {
        rt.isCBT = true;
        rt.isfull = true;
        rt.size = rt.height = 0;
        rt.head = NULL;
        return rt;
    }

    returnType LV = largestCBT(root->left);
    returnType RV = largestCBT(root->right);

    if( (LV.height == RV.height && LV.isfull && RV.isCBT) ||
        (LV.height == RV.height+1 && LV.isCBT && RV.isfull) )
    {
        rt.isCBT = true;
        rt.size = LV.size + RV.size +1;
        rt.height = LV.height+1;
        rt.isfull = LV.size == RV.size && LV.isfull && RV.isfull ? true : false;
        rt.head = root; 
        return rt;
    }
    rt.isCBT = rt.isfull =false;
    rt.size = max(LV.size , RV.size);
    rt.height = max(LV.height , RV.height);
    rt.head = LV.size > RV.size ? LV.head : RV.head;
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

    // root->right->right->left = newNode(45);
    root->right->right->right = newNode(67);

    returnType r = largestCBT(root);
    cout<<"The size is : "<<r.size<<endl;
    cout<<"The height is : "<<r.height<<endl;
    cout<<"The head node is : "<<r.head<<endl;
}