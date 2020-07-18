#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node*left,*right;
};
node* newNode(int key) 
{ 
    node *temp = new node; 
    temp->data = key; 
    temp->left = temp->right = NULL; 
    return temp; 
}

void levelOrder(node*root)
{
    if(root==NULL)
        return;
    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        struct node*ele = q.front();

        if(ele!=NULL)
            cout<<ele->data<<" ";
        if(ele == NULL)
            cout<<endl;
            
        q.pop();

        if(ele!=NULL)
        {
            if(ele->left!=NULL)
                q.push(ele->left);
            if(ele->right!=NULL)
                q.push(ele->right);
        }
        else
        {
            if(!q.empty())
                q.push(NULL);
        }
    }
}

int main()
{

    struct node * root = newNode(20); 
    root->left = newNode(8); 
    root->right = newNode(22); 
    root->left->left = newNode(4); 
    root->left->right = newNode(12); 
    root->left->right->left = newNode(10); 
    root->left->right->right = newNode(14); 

    levelOrder(root);
}
