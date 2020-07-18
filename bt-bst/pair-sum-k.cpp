#include<iostream>
#include<bits/stdc++.h>
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
class RT
{
    public:
    node*first,*sec;
};

RT BTpairSumK(node*root,int k)
{
    RT obj;
    if(root==NULL)
        return obj;
    
    stack<node*>inorder , revinorder;

    node  *low = root , *high = root , *currLow = NULL , *currHigh = NULL;
    bool moveLeft=true,moveRight=true;

    while(1)
    {
        // Inorder 
        while(moveLeft)
        {
            if(low!=NULL)
            {
                inorder.push(low);
                low = low->left;
            }
            else
            {
                currLow = inorder.top();
                inorder.pop();
                moveLeft = false;
                low = currLow->right;
            }
        }

        //Reverse Inorder
        while(moveRight)
        {
            if(high!=NULL)
            {
                revinorder.push(high);
                high = high->right;
            }
            else
            {
                currHigh = revinorder.top();
                revinorder.pop();
                moveRight = false;
                high = currHigh->left;
            }
        }

        if(currLow->data > currHigh->data)
            return obj;
        
        if(currLow->data + currHigh->data == k)
        {
            obj.first = currLow;
            obj.sec = currHigh;
            return obj;
        }

        if(currLow->data + currHigh->data > k)
            moveRight = true;
        else
            moveLeft = true;
    }
}

bool findPair(node* root, int sum,  unordered_set<int> &set) 
{ 
    if (root == NULL) 
        return false; 
  
    if (findPair(root->left, sum, set)) 
        return true; 
  
    if (set.find(sum - root->data) != set.end()) 
    { 
        cout<<"Pair is found :- "<< sum - root->data<<" "<<root->data<< endl; 
        return true; 
    } 
    else
        set.insert(root->data); 
  
    return findPair(root->right, sum, set); 
} 

int main()
{
    node*root = newNode(40);
    root->left = newNode(25);
    root->right = newNode(65);

    root->left->left = newNode(12);
    root->left->right = newNode(35);
    root->right->left = newNode(55);
    root->right->right = newNode(105);

    root->left->left->left = newNode(6);
    root->left->left->right = newNode(18);
    root->left->left->right->left = newNode(15);

    root->right->left->left = newNode(43);
    root->right->left->right = newNode(60);

    root->right->right->left = newNode(75);
    root->right->right->right =  newNode(107);

    RT rt = BTpairSumK(root,90);
    cout<<"The pair is:- "<<rt.first->data<<" "<<rt.sec->data<<endl;

    unordered_set<int> set; 
    if (!findPair(root, 90, set)) 
        cout<<"Pairs do not exit" << endl; 

}
