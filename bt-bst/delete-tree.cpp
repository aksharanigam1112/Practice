#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int key, Node *left = nullptr, Node *right = nullptr)
    {
        this->data = key;
        this->left = left;
        this->right = right;
    }
};

// int getHeight(Node *root)
// {
//     if (!root)
//     {
//         return 0;
//     }
//     queue<Node *> q;
//     Node *front = NULL;
//     int height = 0;
//     q.push(root);
//     while (!q.empty())
//     {
//         int size = q.size();
//         while (size--)
//         {
//             front = q.front();
//             q.pop();
//             if (front->left)
//             {
//                 q.push(front->left);
//             }
//             if (front->right)
//             {
//                 q.push(front->right);
//             }
//         }
//         height++;
//     }
//     return height;
// }

Node *deleteTree(Node *root)
{
    if (root == NULL)
        return NULL;
        
    deleteTree(root->left);
    deleteTree(root->right);
    cout << root->data << " deleting" << endl;

    delete root;
    return NULL;
}

int main()
{
    Node *root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(8);
    root->left->right = new Node(12);
    root->right->left = new Node(16);
    root->right->right = new Node(25);
    root->right->right->left = new Node(26);
    
    Node* ans = deleteTree(root);
    
    if (ans == NULL)
        cout << "Tree deleted "<<root->left->data<<endl;
    else
        cout << "tree deletion failed" << endl;
    return 0;
}