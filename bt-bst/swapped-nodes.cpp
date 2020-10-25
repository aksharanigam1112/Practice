// 2 nodes of  BST are swapped recorrect the BST
#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
    int data;
    node*left,*right;
};

node *newNode(int data)
{
    node *n = new node;
    n->data = data;
    n->left = n->right = NULL;
    return n;
}
void print(node*root)
{
    if(root==NULL)
        return ;
    
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}

void correctBST(node*root,node**first,node**middle,node**last,node**prev)
{
    if(root!=NULL)
    {
        correctBST(root->left,first,middle,last,prev);

        if(*prev && root->data < (*prev)->data)
        {
            if( !*first )
            {
                *first = *prev;
                *middle = root;
            }
            else
                *last = root;
        }
        *prev = root;
 
        correctBST(root->right, first, middle, last, prev );
    }
}

node *swapBack(node*root)
{
    node *first, *middle, *last, *prev;
    first = middle = last = prev = NULL;
 
    correctBST(root,&first,&middle,&last,&prev );
 
    if(first!=NULL && last!=NULL)
        swap(first->data, last->data);

    else if(first!=NULL && middle!=NULL) 
        swap(first->data, middle->data);

    return root;
}

int main()
{
    node *root = newNode(3);
    root->left = newNode(1);
    root->right = newNode(4);
    root->right->left = newNode(2);

    cout<<"Original Tree : ";
    print(root);
    cout<<endl;

    node *newTree = swapBack(root);
    cout<<"Swapped Back Tree : ";
    print(newTree);
    cout<<endl;
}