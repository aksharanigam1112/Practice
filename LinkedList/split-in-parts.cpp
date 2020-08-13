// write a function to split the linked list into k consecutive linked list "parts". 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct ll
{
    int data;
    ll*next;
};
ll* newNode(int data)
{
    ll* n = new ll;
    n->data = data;
    n->next = NULL;
    return n;
}
int countNodes(ll*head)
{
    int count=0;
    while(head)
    {
        count++;
        head = head->next;
    }
    return count;
}

vector<ll*> split(ll*head,int k)
{
    ll* curr = head;
    int N = countNodes(curr);

    int width = N/k, rem = N%k;

    vector<ll*>ans;

    for(int i=0; i<k; i++)
    {
        ll* temp = curr;
        // Rem will tell how many more elements to add to the inital vectors
        int size = width+(i<rem?1:0)-1;
        for(int j=0; j<size; j++) 
        {
            if(curr) 
                curr = curr->next;
        }

        if(curr) 
        {
            ll* prev = curr;
            curr = curr->next;
            prev->next = NULL;
        }
        ans.push_back(temp);
    }
    return ans;
}

void print(ll*head)
{
    if(head==NULL)
        cout<<"NULL";
    while(head)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main()
{
    ll*head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    head->next->next->next->next->next = newNode(6);

    vector<ll*>ans = split(head,4);
    cout<<"Splited linked list : "<<endl;
    for(auto it : ans)
        print(it);
}