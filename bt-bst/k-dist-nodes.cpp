#include<iostream>
using namespace std;
struct node
{
    int data;
    node*left,*right;
};

node* newnode(int key) 
{ 
    node *temp = new node; 
    temp->data = key; 
    temp->left = temp->right = NULL; 
    return temp; 
}

//children at k dist from root
void printAtKDist(node*root,int k)
{
    if(root==NULL || k<0)
        return;
    if(k==0)
    {
        cout<<root->data<<" ";
        return;
    }
    printAtKDist(root->left,k-1);
    printAtKDist(root->right,k-1);
}

// Parents / their children at dist k
int AllNodesKDist(node*root,int k, node* val)
{
    if(root==NULL)
        return -1;
    if(root==val)
    {
        printAtKDist(root,k);
        return 0;
    }

    int LV = AllNodesKDist(root->left,k,val);
    if (LV != -1) 
    { 
         if (LV + 1 == k) 
            cout<<root->data<<" "; 
  
         else
            printAtKDist(root->right, k-LV-2); 
  
         return 1 + LV; 
    } 
  
    int RV = AllNodesKDist(root->right, k , val); 
    if (RV != -1) 
    { 
         if (RV + 1 == k) 
            cout<<root->data<<" "; 
         else
            printAtKDist(root->left, k-RV-2); 
         return 1 + RV; 
    } 
    return -1;
}

int main()
{

    struct node * root = newnode(20); 
    root->left = newnode(8); 
    root->right = newnode(22); 
    root->left->left = newnode(4); 
    root->left->right = newnode(12); 
    root->left->right->left = newnode(10); 
    root->left->right->right = newnode(14); 

    node * target = root->left->right; 
    AllNodesKDist(root, 2 , target); 
    cout<<endl;
    return 0; 
}