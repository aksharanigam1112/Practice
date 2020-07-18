#include<iostream>
using namespace std;
struct node
{
    int data;
    node*left,*right;
};

node* newNode(int data)
{
    node* n = new node();
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}


void inorder(node*root,int k,int &count, int &val)
{
    if(root==NULL)
        return; 

    inorder(root->left,k,count,val);
    
    count++;
    if(count==k)
    {
        val = root->data;
        return;
    }
    inorder(root->right,k,count,val);
}

int kthSmallest(node*root, int k)
{
    int val=0,count=0;
    inorder(root,k,count,val);
    return val;
}


int main()
{
    node*root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(21);

    root->left->left = newNode(3);
    root->left->right = newNode(7);

    root->right->left = newNode(11);
    root->right->right = newNode(45);

    int k = 2;

    cout<<"Kth smallest is : "<<kthSmallest(root,k)<<endl;
}