//  Given a BT root, a node X in the tree is named good 
// if in the path from root to X there are no nodes with a value > than X.
// Return the number of good nodes in the BT. 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node*left,*right;
};
node* newNode(int data)
{
    node* n = new node;
    n->left = n->right = NULL;
    n->data = data;
    return n;
}

class Solution
{
    public :
    int count;
    
    void checkGoodNodes(node*root,int max_val)
    {
        if(root==NULL)
            return ;
        max_val = max(root->data,max_val);

        if(max_val==root->data)
            count+=1;

        checkGoodNodes(root->left,max_val);
        checkGoodNodes(root->right,max_val);
    }

    int goodNodes(node* root)
    {
        if(root==NULL)
            return 0;
        
        count = 1;
        int max_val = root->data;
        checkGoodNodes(root->left,max_val);
        checkGoodNodes(root->right,max_val);
        return count;
    }
};

int main()
{
    node *root = newNode(3);
    root->left = newNode(3);
    
    root->left->left = newNode(4);
    root->left->right = newNode(2);
    
    Solution s;

    cout<<"Good nodes : "<<s.goodNodes(root)<<endl;
}