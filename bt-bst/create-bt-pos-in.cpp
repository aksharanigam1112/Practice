// Create BST from its postorder and inorder traversal
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
node* createBT(int in[], int pos[], int start, int end, int &index)
{
    if(start>end)
        return NULL;

    int point = findIndex(in,pos[index],start,end);
    node*root = new node;
    
    root->data = pos[index];
    index--;

    root->right = createBT(in,pos,point+1,end,index);
    root->left = createBT(in,pos,start,point-1,index);
    
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

void printPostorder(node*root)
{
    if(root==NULL)
        return ;
    printPostorder(root->left);
    printPostorder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    int inorder[] = {1,2,3,4,5,6,7};
    int postorder[] = {1,2,4,3,7,6,5};
    int nodes = sizeof(inorder)/sizeof(inorder[0]);
    int index = nodes-1;
    node*root = createBT(inorder,postorder,0,nodes-1,index);

    cout<<"After tree creation : "<<endl;

    cout<<"Inorder traversal is : ";
    printInorder(root);
    cout<<endl;
    
    cout<<"Postorder traversal is : ";
    printPostorder(root);
    cout<<endl;
}