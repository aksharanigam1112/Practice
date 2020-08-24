#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node
{
    char data;
    node*left,*right;
};

node* newNode(char data)
{
    node* ele = new node;
    ele->data = data;
    ele->left = ele->right = NULL;
    return ele;
}

node* commonAncestor(node*root,node*p1,node*p2)
{
    if(root==NULL)
        return NULL;
        
    if(root==p1 || root==p2)
       return root;
    
    node* LV = commonAncestor(root->left,p1,p2);
    node* RV = commonAncestor(root->right,p1,p2);

    if(LV!=NULL && RV!=NULL)
        return root;
    else
        return (LV!=NULL ? LV:RV);
    
}


// node* commonAncestor(node*root,node*p1,node*p2)
// {
//     if(root==NULL)
//         return NULL;
    
//     node* LV = commonAncestor(root->left,p1,p2);
//     node*RV = commonAncestor(root->right,p1,p2);

//     if(LV!=NULL && RV!=NULL)
//         return root;

//     if(LV!=NULL || RV!=NULL)
//     {
//         if(root==p1 || root==p2)
//             return root;
//         else
//             return (LV!=NULL ? LV:RV);
//     }
//     if(root==p1 || root==p2)
//         return root;
//     else
//         return  NULL;    
// }

int main()
{
    struct node*root = newNode('a');

    root->left = newNode('b');
    root->right = newNode('c');

    root->left->left = newNode('d');
    root->left->right = newNode('e');
    root->right->right = newNode('p');

    root->left->left->left = newNode('f');
    root->left->left->left->left = newNode('g');
    root->left->left->left->right = newNode('h');

    root->left->right->left = newNode('i');
    root->left->right->right = newNode('j');

    root->right->right->left = newNode('q');
    root->right->right->right = newNode('r');

    node*p1 = root->left->left;
    node*p2 = root;
    cout<<"Common ancestor of "<<p1->data<<" and "<<p2->data<<" : "<<commonAncestor(root,p1,p2)->data<<endl;
}

