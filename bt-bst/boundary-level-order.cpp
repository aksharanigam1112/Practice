// Given a BT, the task is to print all levels of this tree in Boundary Level order traversal.
// Boundary Level order traversal: In this traversal, the first element of the level 
// (starting boundary) is printed first, followed by last element (ending boundary). 
// Then the process is repeated for the second and last-second element and so on.
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
    node*n = new node;
    n->data = data;
    n->right = n->left = NULL;
    return n;
}

int totalNodes(node*root)
{
    if(root==NULL)
        return 0;

    return 1 + totalNodes(root->left) + totalNodes(root->right);
}

void printFirstLast(node* q[], int index, int size)
{
    while(index<size)
    {
        cout<<q[index++]->data<<" "<<q[size--]->data<<" ";
    }
    if(index==size)
        cout<<q[index]->data<<" ";
    cout<<endl;
}

void printLevel(node*root, node*q[], int index, int size)
{
    cout<<q[index]->data<<endl;

    while(index<size)
    {
        int curr_size = size;
        while(index<curr_size)
        {
            node* temp = q[index];
            if(temp->left)
                q[size++] = temp->left;
            if(temp->right)
                q[size++] = temp->right;
            index++;
        }
        printFirstLast(q,index,size-1);
    }
}

void boundaryLevelOrder(node*root)
{
    int size = totalNodes(root);
    node *q[size];
    q[0] = root;
    printLevel(root,q,0,1);
}

int main()
{
    node* root = newNode(7);
    root->left = newNode(22);
    root->right = newNode(19);
    
    root->left->left = newNode(3);
    root->left->right = newNode(6);
    root->right->right = newNode(13);
    
    root->left->left->left = newNode(1);
    root->left->left->right = newNode(5);
    root->left->right->right = newNode(8);
    root->right->right->left = newNode(1);
    root->right->right->right = newNode(4);

    root->left->right->right->left = newNode(23);
    boundaryLevelOrder(root);
}