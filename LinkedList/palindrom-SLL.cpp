#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class SLL
{
    public:
    char data;
    SLL *next;
};


SLL* reverseRecur(SLL*head)
{
    if(head==NULL || head->next == NULL )
        return head;
    
    SLL * newhead = reverseRecur(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}

SLL * getMid(SLL*head)
{
    int count=0;
    SLL *flag = head;
    while(flag!=NULL)
    {
        count++;
        flag = flag->next;
    }
    int mid = 0;
    while(mid<count/2)
    {
        mid++;
        head = head->next;
    }
    return head;
}


bool isListPalindrome(SLL*head)
{
    if(head==NULL || head->next == NULL)
        return true;
    SLL * mid = getMid(head);
    SLL *shead = 
}