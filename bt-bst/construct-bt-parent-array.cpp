// Given an array that represents a tree in such a way that array indexes are values 
// in tree nodes and array values give the parent node of that particular index (or node)
#include<iostream>
using namespace std;
struct node
{
    int data;
    node*left,*right;
};
node* newNode(int ele)
{
    node* n = new node;
    n->data = ele;
    n->left = n->right = NULL;
    return n;
}
void print(node*root)
{
    if(root==NULL)
        return;
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}

void createNode(int arr[], int &i, node*create[], node**root)
{
    if(create[i]!=NULL)
        return;
    create[i] = newNode(i);
    if(arr[i]==-1)
    {
        *root = create[i];
        return;
    }
    if(create[arr[i]]==NULL)
        createNode(arr,arr[i],create,root);
    
    node* p = create[arr[i]];
    if(p->left==NULL)
        p->left = create[i];
    else
        p->right = create[i];
}

node* construct(int arr[], int size)
{
    node* create[size];
    for(int i=0;i<size;i++)
        create[i]=NULL;
    node*root = NULL;
    for(int i=0;i<size;i++)
        createNode(arr,i,create,&root);
    return root;
}

int main()
{
    int arr[] = {1,5,5,2,2,-1,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    node*root = construct(arr,size);
    print(root);
    cout<<endl;
}
