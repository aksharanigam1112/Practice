// Convert bst to linked list
#include<iostream>
using namespace std;

struct node
{
    int data;
    node*left,*right;
};
node* newNode(int key) 
{ 
    node *temp = new node; 
    temp->data = key; 
    temp->left = temp->right = NULL; 
    return temp; 
}

node* flatten(node*root)
{
    if(root==NULL)
        return NULL;
    
    node* lv = flatten(root->left);
    node* rv = flatten(root->right);
    
    node* temp = lv;
    if(temp!=NULL)
    {
        while(temp->right!=NULL)
        {
            temp = temp->right;
        }

        temp->right = rv;
        root->right = lv;
        root->left = NULL;
    }
    return root;
}

void inorder(node*root)
{
    if(root==NULL)
        return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    struct node *root = newNode(2);
    root->left = newNode(5); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(8); 
    root->right->right = newNode(1); 
    
    root = flatten(root);
    inorder(root);
    cout<<endl;
}
