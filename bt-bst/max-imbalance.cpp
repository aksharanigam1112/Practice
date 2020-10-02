// imbalance of a tree = abs(height of the left subtree -  height of the right subtree).
#include<iostream>
using namespace std;
struct node
{
    int data;
    node *left, *right;
};
struct returnType
{
    int height, maxImbal;
};

node* newNode(int data)
{
    node*n = new node;
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

returnType imbalance(node* root)
{
    returnType rt;
    if(root==NULL)
    {
        rt.height = 0;
        rt.maxImbal = 0;
        return rt;
    }

    returnType LV = imbalance(root->left);
    returnType RV = imbalance(root->right);

    rt.height = 1+ max(LV.height,RV.height);
    rt.maxImbal = abs(LV.height-RV.height);
    return rt;
}


int main()
{
    node *root = newNode(2);
    root->left = newNode(6);
    root->right = newNode(3);

    root->left->left = newNode(11);
    root->left->right = newNode(8);
    root->left->right->right = newNode(1);

    cout<<"Maximum Imbalance : "<<imbalance(root).maxImbal<<endl;
    
}
