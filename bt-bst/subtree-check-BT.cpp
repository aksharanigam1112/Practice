// Check if one tree is a subtree of the other or not
#include<iostream>
#define MAX 128
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node*left,*right;
};

node* newNode(int data)
{
    node*n = new node;
    n->data=data;
    n->left=n->right=NULL;
}

// Brute Force TC : O(N*M)
bool isSame(node*t1, node*t2)
{
    if(t1==NULL && t2==NULL)
        return true;
    if(t1==NULL || t2==NULL)
        return false;
    
    return(t1->data == t2->data && isSame(t1->left,t2->left) && isSame(t1->right,t2->right));
}

bool isSubtree(node*t1, node*t2)
{
    if(t2==NULL)
        return true;
    if(t1==NULL)
        return false;
    
    if(isSame(t1,t2))
        return true;
    return (isSubtree(t1->left,t2) || isSubtree(t1->right,t2));
}

// Optimized by storing and checking pre & inorder traversals TC : O(M+N) 
void storeInorder(node* root, char arr[], int& i) 
{ 
    if (root == NULL) 
    { 
        arr[i++] = '$'; 
        return; 
    } 
    storeInorder(root->left, arr, i); 
    arr[i++] = (char)(root->data); 
    storeInorder(root->right, arr, i); 
} 
  
void storePreOrder(node* root, char arr[], int& i) 
{ 
    if (root == NULL) 
    { 
        arr[i++] = '$'; 
        return; 
    } 
    arr[i++] = (char)(root->data); 
    storePreOrder(root->left, arr, i); 
    storePreOrder(root->right, arr, i); 
} 
  
bool isSubtree2(node* T, node* S) 
{ 
    if (S == NULL) 
        return true; 
    if (T == NULL) 
        return false; 
  
    int m = 0, n = 0; 
    char inT[MAX], inS[MAX]; 
    
    storeInorder(T, inT, m); 
    storeInorder(S, inS, n); 
    
    inT[m] = '\0', inS[n] = '\0'; 
  
    if (strstr(inT, inS) == NULL) 
        return false; 
  
    m = 0, n = 0; 
    char preT[MAX], preS[MAX]; 
    
    storePreOrder(T, preT, m); 
    storePreOrder(S, preS, n); 
    
    preT[m] = '\0', preS[n] = '\0'; 
  
    return (strstr(preT, preS) != NULL); 
}


int main()
{
    node* t1 = newNode(1);
    t1->left = newNode(2);
    t1->right = newNode(3);
    t1->left->left = newNode(4);
    t1->left->right = newNode(5);
    t1->left->right->left = newNode(6);
    t1->left->right->left->left = newNode(7);
    t1->left->right->left->right = newNode(8);

    node*t2 = newNode(5);
    t2->left = newNode(6);
    t2->left->left = newNode(7);
    t2->left->right = newNode(8);

    cout<<"Is subtree or not BF : "<<(isSubtree(t1,t2)?"Yes":"No")<<endl;
    cout<<"Is subtree or not OPT : "<<(isSubtree2(t1,t2)?"Yes":"No")<<endl;

    
}