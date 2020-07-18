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

int SumOfMultLevel(node*root)
{
    if(root==NULL)
        return 0;
    int sum=0,mult=1;
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(q.size())
    {
        node * ele = q.front();
        q.pop();
        if(ele == NULL)
        {
            sum+=mult;
            mult=1;
            if(q.size())
                q.push(NULL);
        }
        else
        {
            mult*=ele->data;
            if(ele->left!=NULL)
                q.push(ele->left);
            if(ele->right!=NULL)
                q.push(ele->right);
        }
    }
    return sum;
}


int main()
{
    struct node *root = newNode(2);
    root->left = newNode(5);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(8);
    root->right->left = newNode(4);
    root->right->left->right = newNode(10);
    int ans = SumOfMultLevel(root);
    cout<<ans<<endl;
}
