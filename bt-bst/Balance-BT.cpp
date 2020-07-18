#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class ReturnType
{
    public:
        int height;
        bool isbal;
};

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

// BRUTE FORCE


// int getHeight(node*root)
// {
//     if(root==NULL)
//         return 0;
//     return max(getHeight(root->left),getHeight(root->right))+1;
// }

// bool isBalanced(node*root)
// {
//     if(root==NULL)
//         return true;
//     bool LV = isBalanced(root->left);
//     bool RV = isBalanced(root->right);
//     bool currnode = abs(getHeight(root->left) - getHeight(root->right))<=1 ? true : false;
//     return LV && RV && currnode; 
// }


// OPTIMIZED SOLUTION

ReturnType isBalanced(node*root)
{
    ReturnType obj ;

    if(root==NULL)
    {
        obj.height=0;
        obj.isbal=true;
        return obj;
    }

    ReturnType LV = isBalanced(root->left);
    ReturnType RV =  isBalanced(root->right);
    bool currnode = abs(LV.height - RV.height)<=1 ? true : false;
    obj.height = max(LV.height , RV.height)+1;
    obj.isbal =  LV.isbal && RV.isbal && currnode;
    return obj; 
}


int main()
{
    struct node *root = newNode(2);
    root->left = newNode(5);
    // root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(8);
    // root->right->left = newNode(4);
    ReturnType ans = isBalanced(root);
    cout<<ans.isbal<<endl;
}
