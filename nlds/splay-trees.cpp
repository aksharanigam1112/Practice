#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int key=0;
    Node* left,* right;
};

Node* rightRotate(Node* root)
{
    Node* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    return temp;
}

Node* leftRotate(Node* root)
{
    Node* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    return temp;
}

Node* deletion(int key,Node*root)
{
    Node* temp;
    if (!root)
        return NULL;
    
    root = splay(key,root);
    if(key!=root->key)
        return root;
    
    if(!root->left)
    {
        temp=root;
        root = root->right;
    }
    else
    {
        temp = root;
        root=splay(key,root->left);
        root->right = temp->right;
    }
    free(temp);
    return root;
}

Node* splay(int key,Node* root)
{
    if(root==NULL || root->key==key)
        return root;
    
    if(root->key>key)
    {
        if(root->left==NULL)
            return root;
        
        if(root->left->key>key)
        {
            root->left->left = splay(key,root->left->left);
            root = rightRotate(root);
        }
        else if(root->left->key >key)
        {
            root->left->right=splay(key,root->left->right);
            if(root->left->right!=NULL)
                root->left = leftRotate(root->left);
        }
    }
    else
    {
        if(root->right==NULL)
            return root;
        
        if(root->right->key>key)
        {
            root->right->left = splay(key,root->right->left);
            if(root->right->left!=NULL)
                root->right = rightRotate(root->right);
            
        }
        else if(root->right->key >key)
        {
            root->right->right=splay(key,root->right->right);
            root = leftRotate(root);
        }
    }
}

Node* insertNode(Node* node,Node* root)
{
    if(root==NULL)
    {
        root=node;
        return root;
    }
    root = splay(node->key,root);
    if(root->key==node->key)
        return root;
    
    if(root->key<node->key)
    {
        node->left=root;
        node->right=root->right;
        root->right=NULL;
    }
    else
    {
        node->right=root;
        node->left=root->left;
        root->left=NULL;
    }
    return node;
}

Node* search(int key,Node *root)  
{  
    return splay(key,root);  
}

void inorder(Node* root)
{
    if (root != NULL)  
    {  
        inorder(root->left);  
        cout<<root->key<<" "; 
        inorder(root->right);  
    }
}

Node* newNode(int data)
{
    struct Node* node = new struct Node();
    node->key=data;
    node->left=NULL;
    node->right=NULL;
}

int main()
{
    int c=1;
    Node* root = new Node();
    root=NULL;
    do
    {
        if(c==1)
        {
            cout<<"\nEnter data to be inserted:-";
            int data;
            cin>>data;
            Node* node=newNode(data);
            root = insertNode(node,root);
            inorder(root);
        }
        if(c==2)
        {
            cout<<"\nEnter key to be searched";
            int data;
            cin>>data;
            search(data,root);
        }
        if(c==3)
        {
            cout<<"\nEnter key to be searched";
            int data;
            cin>>data;
            search(data,root);
        }
        if(c==4)
        {
            inorder(root);
        }
        cout<<"\n\n0. Exit 1. Insert 2. Delete 3. Search 4. Print Inorder";
        cin>>c;
    }while(c!=0);
    return 0;
}

