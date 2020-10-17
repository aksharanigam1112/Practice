// Given a Binary Tree where all values are from 0 to n-1. 
// Construct an ancestor matrix mat[n][n].
// Ancestor matrix is defined as below.
// mat[i][j] = 1 if i is ancestor of j
// mat[i][j] = 0, otherwise
#include<iostream>
#include<vector>
using namespace std;
#define Max 10

int mat[Max][Max];

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

void print(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }
}

int constructMatrix(node*root, vector<int>&anc)
{
    if(root==NULL)
        return 0;
    
    int data = root->data;
    for(int i=0;i<anc.size();i++)
        mat[anc[i]][data] = 1;

    anc.push_back(data);

    int LV = constructMatrix(root->left,anc);
    int RV = constructMatrix(root->right,anc);

    anc.pop_back();
    return LV+RV+1;
}


int main()
{
    node* root = newNode(5);
    root->left = newNode(1);
    root->right = newNode(2);
    root->left->left = newNode(0);
    root->left->right = newNode(4);
    root->right->left = newNode(3);

    vector<int>anc;
    int n = constructMatrix(root,anc);
    cout<<"Ancestor Matrix is : "<<endl;
    print(n);
}