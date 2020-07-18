#include<iostream>
using namespace std;
struct node
{
    int data;
    node*left,*right;
};

node* newNode(int data)
{
    node*n = new node();
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

bool mirror(node*root1, node*root2)
{
    if(root1==NULL && root2==NULL)
        return true;
    
    if( (root1==NULL && root2!= NULL) || (root1!=NULL && root2==NULL) )   
        return false;

    return mirror(root1->left, root2->right) && mirror(root1->right, root2->left);
}


bool isSymmetric(node* root) 
{
    if(root==NULL)
        return true;
        
    if(root->left!=NULL && root->right!=NULL)
        return mirror(root->left,root->right);
        
    if(root->left==NULL && root->right==NULL)
        return true;
        
    return false;
}

int main()
{
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    root->left->left = newNode(4);
    root->left->right = newNode(6);
    root->left->left->left = newNode(8);

    root->right->right = newNode(5);
    root->right->left = newNode(7);
    root->right->right->right = newNode(9);
    
    cout<<"Is the tree Symmetric ?? "<<(isSymmetric(root) ==1 ? "YES" : "NO")<<endl;

}