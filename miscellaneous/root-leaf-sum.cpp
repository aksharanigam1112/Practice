// Given a BT containing digits from 0 to 9 only.
// Each root-to-leaf path in the tree represents a number. (1->2->3 = 123)
// Return the total sum of all root-to-leaf numbers.
#include<iostream>
using namespace std ;

struct node {
    int data;
    node* left,*right;
};

node* newNode(int data){
    node *n = new node;
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

int findPathSum(node *root, int total)
{
    if (root == NULL)
        return 0;

    int sum = total*10 + root->data;

    if (root->left== NULL && root->right == NULL)
        return sum;

    int lv = findPathSum(root->left,sum);
    int rv = findPathSum(root->right,sum);

    return lv+rv;
}

int totalSum(node*root)
{
    int total = 0;
    if (root==NULL)
        return 0;
    int ans = findPathSum(root,total);
    return ans;
}

int main(){

    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    root->left->left = newNode(4);
    root->left->right = newNode(1);

    cout<<"Root-Leaf paths total sum : "<<totalSum(root)<<endl;
}