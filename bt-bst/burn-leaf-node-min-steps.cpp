// Minimum time to burn a Tree starting from a Leaf node.
// Reference : https://www.geeksforgeeks.org/minimum-time-to-burn-a-tree-starting-from-a-leaf-node/

#include<iostream>
using namespace std;

struct node{
    int data;
    node*left,*right;
};

struct RT {
    int height, dist;

    RT(int h, int d){
        height = h;
        dist = d;
    }
};

node* newNode(int data){
    node*n = new node;
    n->data = data;
    n->left = n->right = NULL;
    return n;
}


int burnTime(node* root, int leaf, int &dist, int &ans){
    if (root == NULL)
        return 0;

    if (root->data == leaf) {
        dist = 0;
        return 1;
    }

    int ldist = -1, rdist = -1;
    int lh = burnTime(root->left, leaf, ldist, ans);
    int rh = burnTime(root->right, leaf, rdist, ans);
 
    if (ldist != -1) {
        dist = ldist + 1;
        ans = max(ans, dist + rh);
    }
    else if (rdist != -1) {
        dist = rdist + 1;
        ans = max(ans, dist + lh);
    }
    return max(lh, rh) + 1;
}

int main(){
    node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 

    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 

    root->left->left->left = newNode(8); 
    root->left->right->left = newNode(9); 
    root->left->right->right = newNode(10); 
    
    root->left->right->left->left = newNode(11); 

    int dist = -1, ans = 0;
    burnTime(root, 11, dist, ans);
    cout<<"Minimum time required to burn all nodes : "<<ans<<endl;
}
