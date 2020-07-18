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

// use hash to store the level order and then print first left to right & the vice-versa


// using 2 stacks
void zigZag(node*root)
{
    stack<node*>curr,next;
    bool LRdir = false;
    curr.push(root);
    while(1)
    {
        while(!curr.empty())
        {
            node *ele = curr.top();
            curr.pop();

            cout<<ele->data<<" ";
            if(LRdir == false)
            {
                if(ele->left != NULL)
                    next.push(ele->left);
                if(ele->right!=NULL)
                    next.push(ele->right);    
            }
            else
            {
                if(ele->right != NULL)
                    next.push(ele->right);
                if(ele->left!=NULL)
                    next.push(ele->left);    
            }
        }
        if(next.empty())
            break;
        LRdir = !LRdir;
        swap(curr,next);
        cout<<endl;
    }
    cout<<endl;
}


int main()
{
    struct node *root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    // root->left->left = newNode('d');
    // root->left->right = newNode('e');
    root->right->right = newNode(7);
    root->right->left = newNode(15);
    // root->left->right->left = newNode('f');
    // root->left->right->right = newNode('g');
    // root->left->right->left->left = newNode('o');
    // root->left->right->right->left = newNode('p');
    // root->left->right->right->right = newNode('l');

    zigZag(root);
}
