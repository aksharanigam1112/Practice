// Prune a binary tree if the root to any-node path sum > k, delete all such nodes 
#include<iostream>
using namespace std;
struct node
{
    int data;
    node*left,*right;
};

node* newNode(int data)
{
    node *n = new node;
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

void print(node *root) 
{ 
    if(root==NULL)
        return;
    print(root->left);
    cout<<root->data<<" ";
    print(root->right); 
}

node* prune(node*root,int k,int &sumSoFar)
{
    if(root==NULL)
        return NULL;
    
    int sum = sumSoFar + root->data; 

    if(sum > k)
    {
        free(root);
        root=NULL;
        return NULL;
    }

    root->left = prune(root->left,k,sum);
    root->right = prune(root->right,k,sum);

    return root;
}

int main()
{
    node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 

    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7);

    root->left->left->left = newNode(8); 
    root->left->left->right = newNode(9); 
    root->left->right->left = newNode(12); 
    root->right->right->left = newNode(10); 

    root->right->right->left->right = newNode(11); 
    root->left->left->right->left = newNode(13); 
    root->left->left->right->right = newNode(14); 

    root->left->left->right->right->left = newNode(15); 

    cout<<"Before pruning : "<<endl;
    print(root);
    cout<<endl;
    
    int sumSoFar=0;
    root = prune(root,20,sumSoFar);
    
    cout<<"After pruning : "<<endl;
    print(root);
    cout<<endl;
}