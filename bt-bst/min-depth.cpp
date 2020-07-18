//Given a binary tree, find its minimum depth.
// The minimum depth is the number of nodes along 
// the shortest path from the root node down to the nearest leaf node.
#include<iostream>
#include<math.h>
using namespace std;
struct node
{
    int data;
    node*left,*right;
};

node* newNode(int data)
{
    node*n = new node;
    n->data=data;
    n->left=n->right=NULL;
    return n;
}

int minDepth(node* root) 
{
    if(root==NULL)
        return 0;
    int LV = minDepth(root->left);
    int RV = minDepth(root->right);
        
    int ans;
    if(LV!=0 && RV!=0)
        ans = min(LV,RV)+1;
    else
        ans = LV==0 ? (RV==0 ? 1 : RV+1):(RV==0 ? LV+1 : 1);
    return ans;
}

int main()
{
    node* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    cout<<"Min depth : "<<minDepth(root)<<endl;
}