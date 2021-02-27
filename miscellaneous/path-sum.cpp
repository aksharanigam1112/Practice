// Given the root of a BT and an integer targetSum, 
// return true if the tree has a root-to-leaf path 
// such that adding up all the values along the path equals targetSum.
#include<iostream>
using namespace std;

struct node
{
    node *left,*right;
    int data;
};

node * newNode(int data)
{
    node *n = new node;
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

bool pathSum(node*root, int target){

    if(root == NULL)
        return false;
    if(root->left == NULL && root->right == NULL && target == root->data)
        return true;
    return pathSum(root->left,target-root->data) || pathSum(root->right, target-root->data);
}

int main()
{
    node *root = newNode(5);
    root->left = newNode(4);
    root->right = newNode(8);

    root->left->left = newNode(11);
    root->right->left = newNode(13);
    root->right->right = newNode(4);

    root->left->left->left = newNode(5);
    root->left->left->right = newNode(2);
    root->right->right->right = newNode(1);

    // node  *root = newNode(-2);
    // root->right = newNode(-3);

    int target = -5;

    cout<<"Path sum exists or not ? "<<(pathSum(root,target)?"Yes":"No")<<endl;

}