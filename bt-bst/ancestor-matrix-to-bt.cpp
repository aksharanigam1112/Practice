// Given an ancestor matrix mat[n][n] 
// Construct a binary tree from it
// Ancestor matrix is defined as below.
// mat[i][j] = 1 if i is ancestor of j
// mat[i][j] = 0, otherwise
#include<iostream>
#include<map>
using namespace std;
#define N 6

struct node
{
    int data;
    node*left,*right;
};

node* newNode(int data)
{
    node* n = new node;
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

void print(node*root)
{
    if(root==NULL)
        return ;
    
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}

node* constructAncestorTree(int mat[N][N])
{
    node* root = NULL;

    // Sum is used as key and row 
    // numbers are used as values 
    multimap<int,int> mm;

    for(int i=0;i<N;i++)
    {
        int sum=0;
        for(int j=0;j<N;j++)
            sum+= mat[i][j];
        
        mm.insert({sum,i});
    }

    node * n[N];
    int parent[N] = {0};

    for(auto it : mm)
    {
        n[it.second] = newNode(it.second);
        root = n[it.second];

        // if non-leaf node 
        if(it.first!=0)
        {
            for(int i=0;i<N;i++)
            {
                // if parent is not set and ancestor exits
                if(parent[i]==0 && mat[it.second][i]==1)
                {
                    // check for unoccupied left/right node and set parent of node i 
                    if(!n[it.second]->left) 
                        n[it.second]->left = n[i]; 
                    else
                        n[it.second]->right = n[i]; 
  
                    parent[i] = 1; 
                }    
            }
        }
    }
    return root; 
}

int main()
{
    int mat[N][N] = {{ 0, 0, 0, 0, 0, 0 }, 
                    { 1, 0, 0, 0, 1, 0 }, 
                    { 0, 0, 0, 1, 0, 0 }, 
                    { 0, 0, 0, 0, 0, 0 }, 
                    { 0, 0, 0, 0, 0, 0 }, 
                    { 1, 1, 1, 1, 1, 0 }}; 
  
    node*root = constructAncestorTree(mat); 
  
    cout<<"Preorder traversal of tree is :- "; 
    print(root); 
    cout<<endl;
}