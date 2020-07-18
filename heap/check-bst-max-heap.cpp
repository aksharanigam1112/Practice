// For bst to be max heap
// 1) Parent-child relation should hold
// 2) It should be complete bt

#include<iostream>
#include<queue>
using namespace std;
struct node
{
    int data;
    node*left,*right;
};
node* newNode(int val)
{
    node * ele = new node;
    ele->data = val;
    ele->left = ele->right = NULL;
    return ele;
}

bool isPCRelation(node*root)
{
    if(root==NULL)
        return true;
    if(root->left!=NULL && root->left->data > root->data)
        return false;
    if(root->right!=NULL && root->right->data > root->data)
        return false;

    bool LV = isPCRelation(root->left);
    bool RV = isPCRelation(root->right);
    return LV&&RV;
}

bool isComplete(node*root)
{
    queue<node*>q;
    bool foundNull=false;
    q.push(root);
    while(!q.empty())
    {
        node*ele = q.front();
        // if(ele!=NULL)
        //     cout<<ele->data<<" ";
        // else
        //     cout<<"NULL ";
        q.pop();

        if(ele!=NULL && foundNull==false)
        {
            q.push(ele->left);
            q.push(ele->right);
        }
        else if(ele==NULL && foundNull==false)
            foundNull = true;

        else if(ele!=NULL && foundNull==true)
            return false;        
    }
    // cout<<endl;
    return true;
}

bool isMaxHeap(node*root)
{
    bool pcValid = isPCRelation(root);
    bool isCBT = isComplete(root);
    return pcValid && isCBT;
}

int main()
{
    node*root = newNode(80);
    root->left = newNode(70);
    root->right = newNode(60);

    root->left->left = newNode(65);
    root->left->right = newNode(55);

    root->right->left = newNode(48);
    root->right->right = newNode(51);

    cout<<"Is BST Max Heap : "<<(isMaxHeap(root)==true ? "YES" : "NO")<<endl; 
}