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

int main()
{
    node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(6);

    root1->left->left = newNode(3);
    root1->left->right = newNode(5);
    root1->left->left->left = newNode(4);
    root1->right->right = newNode(5);

    node* root2 = newNode(1);
    root2->left = newNode(6);
    root2->right = newNode(2);

    root2->left->left = newNode(7);
    root2->right->left = newNode(5);
    root2->right->right = newNode(3);
    root2->right->right->right = newNode(4);
    

    cout<<"Are the two trees mirror images ?? "<<(mirror(root1,root2) ==1 ? "YES" : "NO")<<endl;

}