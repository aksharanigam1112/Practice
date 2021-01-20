#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node
{
    char data;
    node*left,*right;
};

node* newNode(char key) 
{ 
    node *temp = new node; 
    temp->data = key; 
    temp->left = temp->right = NULL; 
    return temp; 
}

void printView(map<int,pair<char,int> >&hash)
{
    for(auto it=hash.begin();it!=hash.end();it++)
        cout<<it->second.first<<" ";
    cout<<endl;
}

void bottomView(node*root,int HD , int level,map<int,pair<char,int> >&hash)
{
    if(root==NULL)
        return ;

    if(hash.find(HD) == hash.end())
        hash[HD] = make_pair(root->data,level);
    else
    {
        if(hash[HD].second <= level)
        {
            hash[HD].first = root->data;
            hash[HD].second = level;
        }
    }
    bottomView(root->left,HD-1,level+1,hash);
    bottomView(root->right,HD+1,level+1,hash);
}

int main()
{
    struct node*root = newNode('a');
    root->left = newNode('b');
    root->right = newNode('c');

    root->left->left = newNode('d');
    root->left->right = newNode('e');

    root->right->left = newNode('f');
    root->right->right = newNode('g');

    root->left->left->left = newNode('n');
    root->left->left->right = newNode('h');

    root->left->right->left = newNode('i');

    root->right->left->left = newNode('j');
    root->right->left->right = newNode('k');

    root->right->right->left = newNode('m');
    root->right->right->right = newNode('l');

    map<int,pair<char,int> >hash;
    bottomView(root,0,1,hash);
    printView(hash);
}