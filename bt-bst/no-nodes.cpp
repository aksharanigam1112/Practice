// Find the no. of nodes between and any two given nodes (inorder traversal) 
// (Technq of kth-smallest)

#include<iostream>
#include<math.h>
using namespace std;

struct node
{
    int data,leftcount,totalChild;
    node*left,*right;
};

node* newNode(int data)
{
    node* n = new node();
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    n->leftcount = 0;
    n->totalChild = 0;
    return n;
}

node* storeLeftChilCount(node*root)
{
    if(root==NULL)
        return NULL;

    node*  LV = storeLeftChilCount(root->left);
    node*  RV = storeLeftChilCount(root->right);

    root->leftcount = LV!=NULL ? LV->totalChild+1 : 0;
    root->totalChild = LV != NULL && RV != NULL ? LV->totalChild + RV->totalChild + 2 : 
                                               ( (LV!=NULL ? LV->totalChild+1 : 0 ) + (RV!=NULL ? RV->totalChild+1 : 0)) ;
    return root; 
}

int getPosition(node*root,int val)
{
    if(root==NULL)
        return 0;
    if(root->data == val)
        return root->leftcount+1;
    
    if(val<root->data)
    {
        int LV = getPosition(root->left,val);
        return LV;
    }
    else
    {
        int RV = getPosition(root->right,val);
        return root->leftcount+RV+1;
    }
    
}


int main()
{
    node*root = newNode(40);
    root->left = newNode(20);
    root->right = newNode(55);
    
    root->left->left = newNode(12);
    root->left->right = newNode(35);

    root->right->left = newNode(45);
    root->right->right = newNode(75);

    root->left->left->left = newNode(8);
    root->left->left->right = newNode(15);
    root->left->right->right = newNode(38);

    root->right->left->right = newNode(50);
    root->right->right->left = newNode(60);

    root = storeLeftChilCount(root);

    int x = getPosition(root,15);
    int y = getPosition(root,60);

    cout<<x<<' '<<y<<endl;
    cout<<"No. of nodes are :- "<<y-x-1<<endl;
   
    
}