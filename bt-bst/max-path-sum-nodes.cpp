#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class RT
{
    public:
        int maxPath,RMP;
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

RT getMaxSum(node * root)
{
    RT rt ;
    if(root==NULL)
    {
        rt.maxPath = INT_MIN;
        rt.RMP = INT_MIN;
        return rt;
    }
    RT LV = getMaxSum(root->left);
    RT RV = getMaxSum(root->right);

    rt.maxPath = max(LV.maxPath , RV.maxPath);
    rt.RMP = max(LV.RMP , RV.RMP) > 0 ?  root->data + max(LV.RMP,RV.RMP) : root->data;

    int CV;
    if(root->left == NULL)
        CV = root->data + RV.RMP;
    if(root->right == NULL)
        CV = root->data + LV.RMP;
    if(LV.RMP>0 && RV.RMP>0)
        CV = LV.RMP+RV.RMP+root->data;
    else
        CV = root->data + max(LV.RMP,RV.RMP);

    return rt;
}

int findMaxUtil(node* root, int &res) 
{ 
    if (root == NULL) 
        return 0; 
  
    int l = findMaxUtil(root->left,res); 
    int r = findMaxUtil(root->right,res); 
  
    int max_single = max(max(l, r) + root->data, root->data); 
    int max_top = max(max_single, l + r + root->data); 
  
    res = max(res, max_top); 

    return max_single; 
} 

int main()
{
    struct node *root = newNode(5);
    root->left = newNode(4);
    root->right = newNode(2);

    root->left->left = newNode(3);
    root->left->right = newNode(6);
    root->right->left = newNode(-7);
    root->right->right = newNode(10);

    root->left->right->left = newNode(-4);
    root->left->right->right = newNode(-9);
    root->right->right->left = newNode(-8);
    // RT ans = getMaxSum(root);
    // cout<<ans.RMP<<" "<<ans.maxPath<<endl;
    int result =0;
    findMaxUtil(root,result);
    cout<<"Max path sum : "<<result<<endl;
}
