// The tilt of a tree node is defined as the 
// absolute difference between the sum of all left subtree node values 
// and the sum of all right subtree node values. Null node has tilt 0.
// The tilt of the whole tree is defined as the sum of all nodes' tilt.

#include<iostream>
using namespace std;

struct node
{
    int data;
    node* left,*right;
};

struct RT
{
    int tilt,sum;
};

node* newNode(int data)
{
    node* n = new node;
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

RT tiltBT(node*root)
{
    RT rt;

    if(root==NULL)
    {
        rt.tilt = 0;
        rt.sum = 0;
        return rt;
    }

    RT lv = tiltBT(root->left);
    RT rv = tiltBT(root->right);

    rt.tilt = lv.tilt + rv.tilt + abs(lv.sum-rv.sum);
    rt.sum = lv.sum + rv.sum + root->data;
    return rt;
}

int main()
{
    node*root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    root->left->left = newNode(4);
    root->left->right = newNode(5);

    RT ans = tiltBT(root);
    cout<<"Tilt of the whole tree is : "<<ans.tilt<<endl;
}