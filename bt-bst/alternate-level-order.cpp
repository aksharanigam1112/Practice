#include<iostream>
#include<bits/stdc++.h>
#include<string>
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

void traverseAlternate(map<int,vector<char> > hash,int level)
{
    map<int,vector<char> >::iterator it1 = hash.begin();
    
    while(it1!=hash.end())
    {
        for(int i=0;i<it1->second.size();i++)
        {
            cout<<it1->second[i]<<" ";
        }
        cout<<endl;
        it1++;
        // it1++;
    }
}

void levelOrder(node*root)
{
    int level=1;
    map<int,vector<char> >hash;

    if(root==NULL)
        return;
    
    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        struct node*ele = q.front();
        q.pop();

        if(ele!=NULL)
        {
            hash[level].push_back(ele->data);
            if(ele->left!=NULL)
                q.push(ele->left);
            if(ele->right!=NULL)
                q.push(ele->right);
        }
        else
        {
            level++;
            if(!q.empty())
                q.push(NULL);
        }
    }

    traverseAlternate(hash,level);
}

int main()
{
    struct node * root = newNode('a'); 
    root->left = newNode('b'); 
    root->right = newNode('c'); 
    root->left->left = newNode('d'); 
    root->left->right = newNode('e'); 
    root->left->right->left = newNode('f'); 
    root->left->right->right = newNode('g'); 
    levelOrder(root);
}
