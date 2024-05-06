#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node*left,*right;
};

node* newnode(int key) { 
    node *temp = new node; 
    temp->data = key; 
    temp->left = temp->right = NULL; 
    return temp; 
}

//children at k dist from root
void printAtKDist(node*root,int k)
{
    if(root==NULL || k<0)
        return;
    if(k==0)
    {
        cout<<root->data<<" ";
        return;
    }
    printAtKDist(root->left,k-1);
    printAtKDist(root->right,k-1);
}

// TC : O(N)    &   SC : O(N)
// Parents / their children at dist k
int AllNodesKDist(node*root,int k, node* val)
{
    if(root==NULL)
        return -1;
    if(root==val)
    {
        printAtKDist(root,k);
        return 0;
    }

    int LV = AllNodesKDist(root->left,k,val);
    if (LV != -1) 
    { 
         if (LV + 1 == k) 
            cout<<root->data<<" "; 
  
         else
            printAtKDist(root->right, k-LV-2); 
  
         return 1 + LV; 
    } 
  
    int RV = AllNodesKDist(root->right, k , val); 
    if (RV != -1) 
    { 
         if (RV + 1 == k) 
            cout<<root->data<<" "; 
         else
            printAtKDist(root->left, k-RV-2); 
         return 1 + RV; 
    } 
    return -1;
}


 void print(node* root) {
    if(root == NULL)
        return;

    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
 }

/* -------------------- NEWER APPROACH ---------------------- */

class Tree{

private:
    map<node*, node*> parentMap;
    vector<int> ans;

    // Level order traversal to find parent mapping
    void findParent(node* root) {

        queue<node*>q;
        q.push(root);

        while(!q.empty()) {
            node* ele = q.front();
            q.pop();

            if(ele->left){
                parentMap[ele->left] = ele;
                q.push(ele->left);
            }

            if(ele->right){
                parentMap[ele->right] = ele;
                q.push(ele->right);
            }
        }
    }

    // BFS from target node with distance K
    void findKDistNodes(node*target, int k) {
        queue<node*> q;
        map<node*, bool> visited;

        q.push(target);
        visited[target] = true;
        int dist = 0;

        while(!q.empty()) {
            int size = q.size();

            if(dist == k)
                break;
            
            dist++;

            for(int i=0;i<size;i++) {
                node* node = q.front();
                q.pop();

                if(node->left && !visited[node->left]) {
                    q.push(node->left);
                    visited[node->left] = true;
                }

                if(node->right && !visited[node->right]) {
                    q.push(node->right);
                    visited[node->right] = true;
                }

                // Node must have a parent mapping & the parent of the node must not be visited
                if(parentMap[node] && !visited[parentMap[node]]) {
                    q.push(parentMap[node]);
                    visited[parentMap[node]] = true;
                }

            }
        }

        while(!q.empty()) {
            node* node = q.front();
            q.pop();
            ans.push_back(node->data);
        }
    }


public:

    // TC : O(N)    &    SC : O(N)
    void distanceK(node* root, node* target, int k) {
        findParent(root);

        findKDistNodes(target, k);

        for(int ele : ans){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
};


int main(){

    node* root = newnode(20); 
    root->left = newnode(8); 
    root->right = newnode(22); 

    root->left->left = newnode(4); 
    root->left->right = newnode(12); 
    
    root->left->right->left = newnode(10); 
    root->left->right->right = newnode(14); 

    node* target = root->left; // 8
    int k = 2;

    cout<<"K distance nodes using Recursion : ";
    AllNodesKDist(root, k, target); 
    cout<<endl;
    

    // cout<<"Pre-order traversal : ";
    // print(root);
    // cout<<endl;

    // For newer approach
    Tree t;
    cout<<"K distance nodes using Bfs : ";
    t.distanceK(root, target, k);
}
