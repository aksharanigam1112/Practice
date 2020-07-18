#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int val;
    Node*next;
};
struct Set
{
    Node*head,*tail;
    Set*nextSet;
};
class disjointSet
{
    private:
        map<int,Node*>addressMap;

    public:
        Set* root = NULL;

        void makeset(int data)
        {
            Node* newNode = new Node;
            Set* newSet = new Set;

            newNode->val = data;
            newNode->next = NULL;

            newSet->head = newNode;
            newSet->tail = newNode;
            newSet->nextSet = NULL;

            addressMap[data] = newNode;

            if(root==NULL)
                root = newSet;
            else
            {
                Set*temp = root;
                while(temp->nextSet!=NULL)
                {
                    temp = temp->nextSet;
                }
                temp->nextSet = newSet;
            }
        }

        Node* find(int val)
        {
            return addressMap.find(val)->second;
        }

        void Union(int val1 , int val2)
        {
            Node*node1 , *node2;
            node1 = addressMap.find(val1)->second;
            node2 = addressMap.find(val2)->second;

            Set*temp = root ,*prev = NULL;
            Node*ptr;
            Set *s1,*s2;
            int flag ;

            while(temp!=NULL)
            {
                ptr = temp->head;
                while(ptr!=NULL)
                {
                    if(ptr==node1)
                    {
                        flag = 1;
                        s1 = temp;
                    } 
                    
                    if(ptr==node2)
                    {
                        flag =2;
                        s2 = temp;
                    }
                    ptr = ptr->next;
                }
                if(s1 && s2)
                    break;

                prev = temp;
                temp = temp->nextSet;
            }

            if(flag==1)
            {
                ptr = s2->head;
                while(ptr->next!=NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = s1->head;
                prev->nextSet = s1->nextSet;
                delete(s1);
            }
            if(flag==2)
            {
                ptr = s1->head;
                while(ptr->next!=NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = s2->head;
                prev->nextSet = s2->nextSet;
                delete(s2);
            }
        }
};

int main()
{
    disjointSet obj;
    obj.makeset(1);
    obj.makeset(2);
    obj.makeset(3);
    obj.makeset(4);
    
    cout<<obj.find(2)<<endl;

    obj.Union(1,2);
    obj.Union(3,4);
    cout<<obj.find(2)<<endl;

}