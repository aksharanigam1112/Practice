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

// making key as the view we are considering
// TC : O(n) & SC : O(n)

void printList(list<list<node*> >LV)
{
    list<list<node*> >::iterator it1 = LV.begin();
    
    while(it1!=LV.end())
    {
        list<node*>::iterator it2 = it1->begin();
        while(it2!=it1->end())
        {
            cout<<(*it2)->data<<" ";
            it2++;
        }
        it1++;
        cout<<endl;
    }
}

void leftViewLayerbyLayer(node*root , list<list<node*> >LV)
{
    if(root==NULL)
        return;
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    int posAtLevel = 0, totalLayers=0;
    map<int,list<node*> >hash;

    while(!q.empty())
    {
        node*ele =q.front();
        q.pop();

        if(ele!=NULL)
        {
            posAtLevel++;
            totalLayers = max(posAtLevel,totalLayers);

            hash[posAtLevel].push_back(ele);
            if(ele->left!=NULL)
                q.push(ele->left);
            if(ele->right!=NULL)
                q.push(ele->right);
        } 
        else
        {
            posAtLevel=0;
            if(!q.empty())
                q.push(NULL);
        }
    }
    for(int i=1;i<=totalLayers;i++)
    {
        LV.push_back(hash[i]);
    } 

    printList(LV);
}

// storing in hash & printing element by element from each level 
// TC : O(n^2) SC : O(n)

void printLayerbyLayer(node*root)
{
    if (root == NULL) 
        return;  
        
    queue<node *> q;  
    map<int,string>hash;

    q.push(root);  
    int level = 0,nodeCount=0,max=0;


    while (q.empty() == false)  
    {  
        if(nodeCount==0)
        {
            level++;
            nodeCount = q.size();
            if(nodeCount>max)
                max = nodeCount; 
        }

        node *node = q.front();  
        hash[level]+=node->data; 
        q.pop();  
                
        if (node->left != NULL)  
            q.push(node->left);  
        if (node->right != NULL)  
            q.push(node->right);  
                
        nodeCount--;
    } 

    
    for(int i=0;i<max;i++)
    {
        map<int,string>::iterator it = hash.begin();
        while(it!=hash.end())
        {
            cout<<it->second[i]<<" ";
            if(i == it->second.length()-1)
                    hash.erase(it);
                    
            it++;
        } 
        cout<<endl;
    }
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

    cout<<"Using 1st method : \n";
    printLayerbyLayer(root);

    cout<<"Using 2nd method : \n";
    list<list<node *> >hash;
    leftViewLayerbyLayer(root,hash);

}