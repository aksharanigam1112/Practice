// Given the root of a binary search tree with distinct values, 
// modify it so that every node has a new value equal to 
// the sum of the values of the original tree that are greater than or equal to node->val
#include<iostream>
using namespace std;
struct node
{
    int data;
    node*left,*right;
};
node* newNode(int data)
{
    node*n = new node;
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

void reverseOrder(node*root,int &count)
{
    if(root==NULL)
        return ;

    reverseOrder(root->right,count);

    root->data = root->data+count;
    count = root->data;

    reverseOrder(root->left,count);
    return;
}

node* greaterSumTree(node*root)
{
    int sum=0;
    reverseOrder(root,sum);
    return root;
}

void inorder(node*root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    node* root = newNode(4);
    root->left = newNode(1);
    root->right = newNode(6);

    root->left->left = newNode(0);
    root->left->right = newNode(2);
    root->left->right->right = newNode(3);

    root->right->left = newNode(5);
    root->right->right = newNode(7);
    root->right->right->right = newNode(8);

    cout<<"Original Inorder : ";
    inorder(root);
    cout<<endl;

    node*n = greaterSumTree(root);
    cout<<"Greater Sum Tree Inorder : ";
    inorder(n);
    cout<<endl;
 
}