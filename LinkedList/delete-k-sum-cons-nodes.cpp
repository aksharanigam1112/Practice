// Given the head of a linked list, we repeatedly 
// delete consecutive sequences of nodes that sum to K until there are no such sequences.
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
    ll *n = new ll;
    n->data = data;
    n->next = NULL;
    return n;
}

void print(ll*head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

// TC : O(N) & SC : O(N)
ll* removeSumKNodes(ll*head, int K,bool &foundSum)
{
    ll* root = newNode(0);
    root->next = head;

    map<int,ll*>storeSum;
    storeSum.insert(make_pair(0,root));

    int sum=0;
    while(head!=NULL)
    {
        sum+=head->data;

        // If k sum is formed
        if(storeSum.find(sum-K)!=storeSum.end())
        {   
            // Delete
            foundSum = true;
            ll* prev = storeSum[sum-K];
            ll* start = prev;
            int temp = sum;

            while(prev!=head)
            {
                prev = prev->next;
                temp+=prev->data;
                // Remove the sum from the hash
                if(prev!=head)
                    storeSum.erase(temp);
            }
            start->next = head->next;
            sum=0;
        }
        else
            storeSum[sum] = head;
        
        head = head->next;
    }
    return root->next;
}

ll* deleteK(ll*head,int K)
{
    static bool foundSum=false;
    while(1)
    {
        head = removeSumKNodes(head,K,foundSum);
        if(foundSum==true)
            foundSum = false;
        else
            break;
    }
    return head;
}

int main()
{
    ll *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(-3);
    head->next->next->next->next = newNode(1);

    cout<<"Initial List : ";
    print(head);

    head = deleteK(head,0);
    cout<<"After removing the sum k nodes : ";
    print(head);
}