// Replace every node with the sum of its inorder precessor and successor
#include<iostream>
#include<vector>
using namespace std;
struct node
{
    int data;
    node*left,*right;
};
node* newNode(int data)
{
    node* ele = new node;
    ele->data = data;
    ele->left = ele->right = NULL;
    return ele;
}

void print(node*root)
{
    if(root==NULL)
        return;
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
    cout<<endl;
}

void storeInorder(node* root, vector<int>&arr)
{
    if(root==NULL)
        return;
    storeInorder(root->left,arr);
    arr.push_back(root->data);
    storeInorder(root->right,arr);
}

void replace(node*root, vector<int>&arr, int &i)
{
    if(root==NULL)
        return;
    
    replace(root->left,arr,i);
    root->data = arr[i-1]+arr[i+1];
    i++;
    replace(root->right,arr,i);
}

void sum(node*root)
{
    if(root==NULL)
        return;
    
    vector<int>arr;
    arr.push_back(0);
    storeInorder(root,arr);
    arr.push_back(0);

    int i=1;
    replace(root,arr,i);
}

int main()
{
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    sum(root);
    cout<<"Replaced : ";
    print(root);
}
