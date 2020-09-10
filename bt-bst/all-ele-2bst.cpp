// Given two binary search trees root1 and root2.
// Return a list containing all the integers from both trees sorted in ascending order.
#include<iostream>
#include<vector>
using namespace std;
struct node
{
    int data;
    node* left,*right;
};
node* newNode(int data)
{
    node* n = new node;
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

void allElements(node*root1, node* root2, vector<int>&ans)
{
    if(root1==NULL || root2==NULL)
        return;

    if(root1->data < root2->data)
    {
        allElements(root1->left,root2,ans);
        ans.push_back(root1->data);
        allElements(root1->right,root2,ans);
    }
    else if(root1->data > root2->data)
    {
        allElements(root1,root2->left,ans);
        ans.push_back(root2->data);
        allElements(root1,root2->right,ans);
    }    
    else
    {
        allElements(root1->left,root2->left,ans);
        ans.push_back(root1->data);
        ans.push_back(root2->data);
        allElements(root1->right,root2->right,ans);
    }
}

int main()
{
    node* root1 = newNode(2);
    root1->left = newNode(1);
    root1->right = newNode(4);

    node* root2 = newNode(1);
    root2->left = newNode(0);
    root2->right = newNode(3);

    vector<int> ans;
    allElements(root1,root2,ans);

    for(int i : ans)
        cout<<i<<" ";
    cout<<endl;
}