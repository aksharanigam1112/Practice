// It is equal size of both left and right subtrees 
// OR it has both left & right child

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
    bool isFull;
    int size;
    node* head;
};

node* newNode(int key) 
{ 
    node *temp = new node; 
    temp->data = key; 
    temp->left = temp->right = NULL; 
    return temp; 
}

returnType largestFulltree(node*root)
{
    returnType rt;
    if(root==NULL)
    {
        rt.isFull = true;
        rt.size=0;
        rt.head = NULL;
        return rt;
    }

    returnType LV = largestFulltree(root->left);
    returnType RV = largestFulltree(root->right);

    if(LV.isFull && RV.isFull && LV.size == RV.size)
    {
        rt.isFull = true;
        rt.size = LV.size + RV.size +1;
        rt.head = root;
        return rt;
    }
    rt.isFull = false;
    rt.size = max(LV.size , RV.size);
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

    root->right->right->left = newNode(45);
    root->right->right->right = newNode(67);

    returnType r = largestFulltree(root);
    cout<<"The size is : "<<r.size<<endl;
    cout<<"The root node of the full tree is : "<<r.head->data<<endl;
}