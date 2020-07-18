#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct node
{
    int data;
    vector<node*>children;
};

node* newNode(int data)
{
    node*n = new node;
    n->data = data;
    return n;
}

// DFS
int maxDepth(node* root)
{
    if(root==NULL)
        return 0;
    
    int depth=0;
    for(auto it  : root->children)
    {
        depth = max(maxDepth(it),depth);
    }
    return 1+depth;
}

int main()
{
            //         0
            //     1   2   3
            // 4   5       6   7   8
            // 9 

    node* root = newNode(0);
    (root->children).push_back(newNode(1));
    (root->children).push_back(newNode(2));
    (root->children).push_back(newNode(3));

    (root->children[0]->children).push_back(newNode(4));
    (root->children[0]->children).push_back(newNode(5));

    (root->children[2]->children).push_back(newNode(6));
    (root->children[2]->children).push_back(newNode(7));
    (root->children[2]->children).push_back(newNode(8));

    (root->children[0]->children[0]->children).push_back(newNode(9));

    cout<<"Depth of N-ary tree : "<<maxDepth(root)<<endl;
}
