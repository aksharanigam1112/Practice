#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left, *right;
};

node* newNode(int data)
{
    node* n = new node;
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

vector<double> averageBT(node* root){
    vector<double>ans;
    queue<node*>q;
    double count=0,sum=0;

    if(root==NULL) 
        return ans;
    
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* val = q.front();
        q.pop();

        if(val != NULL){
            sum+=val->data;
            count++;
            if(val->left)
                q.push(val->left);
            if(val->right)
                q.push(val->right);
        }
        else
        {
            ans.push_back(sum/count);
            sum=0;
            count=0;
            if(!q.empty())
                q.push(NULL);
        }        
    }
    return ans;
}

int main()
{
    node *root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    vector<double> ans = averageBT(root);
    for(auto it : ans){
        cout<<it<<" ";
    }
    cout<<endl;
}