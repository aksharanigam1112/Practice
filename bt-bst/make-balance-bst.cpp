// Given a binary search tree, return a balanced binary search tree with the same node values.
// A binary search tree is balanced if and only if 
// the depth of the two subtrees of every node never differ by more than 1.
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
    node*n = new node;
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

// AVL Balancing TC : O(N LogN)

// Inorder Traversal, construct tree TC : O(N) SC : O(N)
void inorder(node*root, vector<int>&arr)
{
    if(root==NULL)
        return;
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}

node* createBalanceBST(vector<int>&arr, int start, int end)
{
    if(start>end)
        return NULL;
    
    int mid = (start+end)/2;
    node*root = new node;
    root->data = arr[mid];
    root->left = createBalanceBST(arr,start,mid-1);
    root->right = createBalanceBST(arr,mid+1,end);
    return root;
}

void print(node*root)
{
    if(root==NULL)
        return ;
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}
 
int main()
{
    node* root = newNode(10); 
    root->left = newNode(8); 
    root->left->left = newNode(7); 
    root->left->left->left = newNode(6); 
    root->left->left->left->left = newNode(5); 
  
    vector<int>arr;
    inorder(root,arr);

    node* head = createBalanceBST(arr,0,arr.size()-1);
    cout<<"Balanced BST : ";
    print(head);
    cout<<endl;
}

