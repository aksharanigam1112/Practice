// Given the root of rt BT, return the length of the longest path, 
// where each node in the path has the same value. 
// This path may or may not pass through the root.
// The length of the path between two nodes is rep by the no. of edges between them
#include<iostream>
using namespace std;
struct node
{
    int data;
    node* left, *right;
};
struct RT
{
    int lmax,rmax;
};

node *newNode(int data)
{
    node * n = new node;
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

RT find(node* root, int &ans)
{
    RT rt;
    rt.lmax = rt.rmax = 0;

    if(root->left == NULL && root->right == NULL)
        return rt;
    
    if(root->left != NULL)
    {
        RT lv = find(root->left,ans);

        if(root->data == root->left->data)
            rt.lmax = 1 + max(lv.lmax,lv.rmax);
    }
    
    if(root->right != NULL)
    {
        RT rv = find(root->right,ans);
        if(root->data == root->right->data)
            rt.rmax = 1 + max(rv.lmax,rv.rmax);
    }
    
    ans = max(ans,max(rt.lmax,rt.rmax));

    if(root->left != NULL && root->right != NULL &&
        root->left->data == root->data && root->right->data == root->data)
            ans = max(ans,rt.lmax+rt.rmax);
    
    return rt;
}

int longUnivaluePath(node* root) 
{
    int ans = 0;
    if(root==NULL)
        return 0;

    find(root,ans);
    return ans;
}

int main()
{
    node * root = newNode(5);
    root->left = newNode(4);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(1);
    root->right->right = newNode(5);

    cout<<"Length of the longest univalue path with value : "<<longUnivaluePath(root)<<endl;
}