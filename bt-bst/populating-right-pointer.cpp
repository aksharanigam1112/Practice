// Populate each next pointer to point to its next right node. 
// If there is no next right node, the next pointer should be set to NULL.
#include<iostream>
#include<queue>
using namespace std;

struct node
{
    int data;
    node*left,*right,*next;
};

node* newNode(int data)
{
    node*n = new node;
    n->data = data;
    n->left = n->right = n->next = NULL;
    return n;
}

void print(node* root)
{
    if(root==NULL)
        return;
    
    cout<<root->data<<" -> "<<(root->next ? root->next->data : -1)<<endl;
    print(root->left);
    print(root->right);
}

void populateRight(node*root)
{
    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node* ele = q.front();
        q.pop();

        if(ele!=NULL)
        {
            ele->next = q.front();
            if(ele->left)
                q.push(ele->left);
            if(ele->right)
                q.push(ele->right);
        }
        else if(!q.empty())
                q.push(NULL);
    }
}

int main()
{
    node*root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    root->left->left = newNode(4);
    root->left->right = newNode(5);

    root->right->left = newNode(6);
    root->right->right = newNode(7);

    populateRight(root);
    cout<<"Nodes with Right Sibling : "<<endl;
    print(root);

}