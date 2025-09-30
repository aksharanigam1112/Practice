#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node*left,*right;
};

node* newNode(int key) { 
    node *temp = new node; 
    temp->data = key; 
    temp->left = temp->right = NULL; 
    return temp; 
}

// Using hash to store the level order and then print left to right & the vice-versa
// TC : O(N)    &   SC : O(N)
void preOrder(node* root, int level, map<int, deque<int>> &hash, bool leftToRight) {
    if(root == NULL)
        return;

    if(leftToRight)
        hash[level].push_back(root->data);
    else
        hash[level].push_front(root->data);

    preOrder(root->left, level+1, hash, !leftToRight);
    preOrder(root->right, level+1, hash, !leftToRight);
}

void spiralOrder(node* root) {
    if(root == NULL)
        return;

    map<int, deque<int>> hash;
    preOrder(root, 1, hash, true);

    for(auto [level, q] : hash) {

        while(!q.empty()){
            int data = q.front();
            q.pop_front();

            cout<<data<<", ";
        }
    }
}

// using 2 stacks
void zigZag(node*root)
{
    stack<node*>curr,next;
    bool LRdir = false;
    curr.push(root);
    while(1)
    {
        while(!curr.empty())
        {
            node *ele = curr.top();
            curr.pop();

            cout<<ele->data<<", ";
            if(LRdir == false)
            {
                if(ele->left != NULL)
                    next.push(ele->left);
                if(ele->right!=NULL)
                    next.push(ele->right);    
            }
            else
            {
                if(ele->right != NULL)
                    next.push(ele->right);
                if(ele->left!=NULL)
                    next.push(ele->left);    
            }
        }
        if(next.empty())
            break;
        LRdir = !LRdir;
        swap(curr,next);
        // cout<<endl;
    }
    cout<<endl;
}


int main() {
    struct node *root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    
    root->right->right = newNode(7);
    root->right->left = newNode(15);

    cout<<"Zig Zag : "; 
    zigZag(root);
    cout<<endl;


    // node *root2 = newNode(1);
    // root2->left = newNode(2);
    // root2->right = newNode(3);

    // root2->left->left = newNode(4);
    // root2->left->right = newNode(5);
    // root2->right->left = newNode(6);
    // root2->right->right = newNode(7);


    // root2->right->right->left = newNode(8);
    // root2->right->right->right = newNode(9);

    cout<<"Spiral Order : ";
    spiralOrder(root);
    cout<<endl;
}
