// Return a list of all possible full binary trees with N nodes.  
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node*left;
    node*right;

    node() : data(0), left(nullptr), right(nullptr) {}
    node(int x) : data(x), left(nullptr), right(nullptr) {}
};

// 0 for all even no. of nodes as they cannot form full tree

int totalFullTrees(int N)
{
    if(N==1)
        return 1;
    if(N%2==0)
        return 0;
    int count=0;
    for(int i=0;i<N;i++)
    {
        count+=totalFullTrees(i)*totalFullTrees(N-i-1);
    }
    return count;
}

unordered_map<int, vector<node*>> cache;
vector<node*> allPossibleFBT(int n)
{
    if(cache.find(n)==cache.end()) 
        return cache[n];

    if(n==1) 
        return vector<node*>{new node(0)};
    --n;
    vector<node*> res;
        
    for(int i=1;i<n;i+=2)
    {
        vector<node*> x = allPossibleFBT(i);
        vector<node*> y = allPossibleFBT(n-i);
        for(int j=0;j<x.size();j++)
        {
            for(int k=0;k<y.size();k++)
            {
                node* root = new node(0);
                root->left  = x[j];
                root->right = y[k];
                res.push_back(root);
            }
        }
    }
    return cache[n] = res;
}

int main()
{
    int n = 7;
    cout<<"Total Full trees possoble : "<<totalFullTrees(n)<<endl;
}