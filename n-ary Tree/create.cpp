// Create an N-ary tree
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

// BFS
void print(node*root)
{
    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node*ele = q.front();
        q.pop();
        
        if(ele!=NULL)
        {
            cout<<ele->data<<" ";
            for(auto i : ele->children)
                q.push(i);
        }
        else
        {
            if(!q.empty())
                q.push(NULL);
            cout<<endl;
        }
    }
}

int main()
{
            //         0
            //     1   2   3
            // 4   5       6   7   8
            // 9 

    node* root = newNode(1);
    (root->children).push_back(newNode(3));
    (root->children).push_back(newNode(2));
    (root->children).push_back(newNode(4));

    (root->children[0]->children).push_back(newNode(5));
    (root->children[0]->children).push_back(newNode(6));

    // (root->children[2]->children).push_back(newNode(6));
    // (root->children[2]->children).push_back(newNode(7));
    // (root->children[2]->children).push_back(newNode(8));

    // (root->children[0]->children[0]->children).push_back(newNode(9));

    print(root);
}
