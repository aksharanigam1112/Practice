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
    return n;
}

int main()
{
    
}