#include<iostream>
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

int countNode(node*root)
{
    if(root==NULL)
        return 0;
    return 1 + countNode(root->left) + countNode(root->right);
}

void findNode(node* root, int x, int &l, int &r)
{
    if(root==NULL)
        return ;
    if(root->data == x)
    {
        l = countNode(root->left);
        r = countNode(root->right);
        return;
    }
    findNode(root->left,x,l,r);
    findNode(root->right,x,l,r);
}

bool colourTree(node*root, int n, int x)
{
    if(n==1)
        return false;
    int l=0,r=0;

    findNode(root,x,l,r);
    
    // left child is considered when number of nodes in left subtree of x are > n/2.
    // OR right child is considered when number of nodes in right subtree of x are > n/2
    if(l>n/2 || r>n/2)
        return true;

    //  parent of x is considered for y
    // when number in nodes in tree of x < (n+1)/2 
    return (l+r+1 < n+1/2);
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

    cout<<"Does player 2 win ? "<<(colourTree(root,8,3) ? "Yes" : "No")<<endl;
}