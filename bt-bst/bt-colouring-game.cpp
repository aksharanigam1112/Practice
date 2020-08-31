// We are given the root of this binary tree and the number of nodes n in the tree.  
// n is odd, and each node has a distinct value from 1 to n.
// Player 1 ==> x ==> Red
// Player 2 ==> y ==> Blue
// If there exists a value of y for which player 2 always win return true else false 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* left,*right;
};

node* newNode(int data)
{
    node*n = new node;
    n->data = data;
    n->left = n->right = NULL;
}

int dfs(node *root,vector<int>&dp,int &x,int &l,int &r)
{
    if(root->left)
        dp[root->data]+=dfs(root->left,dp,x,l,r);
    if(root->right)
        dp[root->data]+=dfs(root->right,dp,x,l,r);

    if(root->data==x)
    {
        l = root->left ? dp[root->left->data]:0;
        r = root->right ? dp[root->right->data]:0;
    }
    return ++dp[root->data];
}

bool colourBT(node* root, int n, int x) 
{
    vector<int>dp(n+1);
    int l,r;
    
    dfs(root,dp,x,l,r);
    if(max(n-dp[x],max(l,r))>n/2)
        return true;
    return false;
}

int main()
{
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    root->left->left = newNode(4);
    root->left->right = newNode(5);

    root->right->left = newNode(8);

    root->left->left->left = newNode(6);
    root->left->left->right = newNode(7);

    cout<<"Does player 2 win ? "<<(colourBT(root,8,3) ? "Yes" : "No")<<endl;
}