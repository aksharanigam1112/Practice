// Given a binary tree, find the leftmost value in the last row of the tree. 
#include<iostream>
#include<queue>
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
    n->left=n->right=NULL;
}

int findLeftmost(node*root)
{
    if(root==NULL)
        return -1;
    
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    int leftmostTillNow = root->data;

    while(!q.empty())
    {
        node* ele = q.front();
        q.pop();
        if(ele!=NULL)
        {
            if(ele->left)
                q.push(ele->left);
            if(ele->right)
                q.push(ele->right);
        }
        else
        {
            if(!q.empty())
            {
                leftmostTillNow = q.front()->data;
                q.push(NULL);
            }
        }   
    }
    return leftmostTillNow;
}

int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->left = newNode(7);

    cout<<"Bottom Leftmost leaf : "<<findLeftmost(root)<<endl;
}