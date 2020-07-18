#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node
{
    char data;
    node*left,*right;
};

node* newNode(char key) 
{ 
    node *temp = new node; 
    temp->data = key; 
    temp->left = temp->right = NULL; 
    return temp; 
}

// TC : O(N) & SC : O(N)

void usingInorder(node* root, int level, int *max_level) 
{ 
    if (root == NULL) 
        return; 

    if (*max_level < level) 
    { 
        cout<<root->data<<" "; 
        *max_level = level; 
    } 
   
    usingInorder(root->left, level + 1, max_level); 
    usingInorder(root->right, level + 1, max_level);
} 

// TC : O(N) & SC : O(N)  
 
void printFirstofLevelOrder(node *root)  
{  
    if (root == NULL) 
        return;  
    
    queue<node *> q;  
    map<int,string>hash;

    q.push(root);  
    int level = 1;
    hash[level]+=root->data;

    while(!q.empty())  
    {  
        int nodeCount = q.size(); 
        while (nodeCount > 0) 
        {  
            node *node = q.front();  
            hash[level]+=node->data; 
            q.pop();  
            
            if (node->left != NULL)  
                q.push(node->left);  
            if (node->right != NULL)  
                q.push(node->right);  
            
            nodeCount--;  
        }
        level++;  
    } 

    map<int,string>::iterator it = hash.begin();
    while(it!=hash.end())
    {
        cout<<it->second[0]<<" ";
        it++;
    } 
    cout<<endl;
}   


int main()
{
    struct node *root = newNode('a');

    root->left = newNode('b');
    root->right = newNode('c');
    root->left->left = newNode('d');
    root->left->right = newNode('e');
    root->right->right = newNode('j');

    root->left->left->left = newNode('f');
    root->left->left->right = newNode('g');
    root->left->right->right = newNode('l');

    root->right->right->left = newNode('k');
    root->right->right->right = newNode('l');

    root->left->left->left->left = newNode('h');
    root->left->left->left->right = newNode('t');
    root->left->left->left->right->left = newNode('p');

    cout<<"Using Level Order : \n";
    printFirstofLevelOrder(root);

    cout<<"Using Inorder : \n";
    int max_level = 0;
    usingInorder(root,1,&max_level);
}
