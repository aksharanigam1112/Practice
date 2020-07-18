#include<iostream>
#include<bits/stdc++.h>
using namespace std;
static int path_count = 0;

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

// From root node only

int getCountFromRoot(node*root,int sumsofar,int k)
{
    if(root==NULL)
        return 0;
    int val = (sumsofar+root->data == k )?1:0;
    return(val+getCountFromRoot(root->left,sumsofar+root->data,k) + getCountFromRoot(root->right,sumsofar+root->data,k));
}

// All possible paths with sum=k 

// BRUTE FORCE :- O(N^2)

int totalPosPaths(node*root,int k)
{
    if(root==NULL)
        return 0;
    int LV =  totalPosPaths(root->left,k);
    int RV =  totalPosPaths(root->right,k);
    return LV+RV+getCountFromRoot(root,0,k);
}

// OPTIMIZED TO :- O(N)

void getTotalPaths(node*root,map<int,int>hash,int k,int sumsofar)
{
    
    if(root==NULL)
        return ;
    int newsum = sumsofar + root->data;
    
    int val = hash.find(newsum-k)->second;
    
    if(val)
        path_count+=val;

    if(hash.find(newsum)->second)
        hash.find(newsum)->second++;
    
    else
        hash.insert(make_pair(newsum,1));
        
    getTotalPaths(root->left,hash,k,newsum);
    getTotalPaths(root->right,hash,k,newsum);
    hash.find(newsum)->second == 0 ? hash.erase(newsum) : hash.find(newsum)->second--;
}

int main()
{
    int k = 5;
    struct node *root = newNode(2);
    root->left = newNode(1);
    root->right = newNode(3);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->left->right = newNode(1);

    struct node * head = root;
    int ans = totalPosPaths(root,k);
    cout<<"\nUsing Brute Force:- "<<ans<<endl;

    map<int,int>hash;
    hash.insert(make_pair(0,1));
    
    getTotalPaths(head,hash,k,0);
    cout<<"\nOptimized cost :- "<<path_count<<endl;
}
