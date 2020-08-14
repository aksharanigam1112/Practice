// Create BST from its preorder and inorder traversal
// No duplicates exist
#include<iostream>
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
}

// TC : O(N)
int findIndex(int in[], int val, int start, int end)
{
    for(int i=start;i<=end;i++)
    {
        if(in[i]==val)
            return i;
    }
}

// Best        TC : O(NlogN)   &   SC : O(logN)
// Worst       TC : O(N^2)     &   SC : O(N)  
node* createBT(int in[], int pre[], int start, int end, int &index)
{
    if(start>end)
        return NULL;

    int point = findIndex(in,pre[index],start,end);
    node*root = new node;
    root->data = pre[index];
    index++;

    root->left = createBT(in,pre,start,point-1,index);
    root->right = createBT(in,pre,point+1,end,index);
    return root;
}

void printInorder(node*root)
{
    if(root==NULL)
        return ;
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

void printPreorder(node*root)
{
    if(root==NULL)
        return ;
    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main()
{
    int inorder[] = {1,2,3,4,5,6,7};
    int preorder[] = {5,3,2,1,4,6,7};
    int nodes = sizeof(inorder)/sizeof(inorder[0]);
    int index = 0;
    node*root = createBT(inorder,preorder,0,nodes-1,index);

    cout<<"After tree creation : "<<endl;

    cout<<"Inorder traversal is : ";
    printInorder(root);
    cout<<endl;
    
    cout<<"Preorder traversal is : ";
    printPreorder(root);
    cout<<endl;
}