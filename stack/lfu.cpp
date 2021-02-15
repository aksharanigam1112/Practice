#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define pp pair<int,int> 

struct comp
{
    bool operator () (pp p1, pp p2)
    {
        return p1.second > p2.second  ;

    }
};

class LFU 
{
    private :
    priority_queue<pp,vector<pp>, comp> pq;
    set<int> hash;
    int size ;

    public : 
    LFU(int s)
    {
        size = s;
    }

    void insert(int key)
    {
        if(hash.find(key) == hash.end())
        {
            if( pq.size() == size)
            {
                auto top = pq.top();
                pq.pop();
                hash.erase(top.first);
            }
            pq.push({key,1});
            hash.insert(key);
        }
        else
        {
            priority_queue<pp,vector<pp>,comp> p2;

            while(!pq.empty())
            {
                auto top = pq.top();
                pq.pop();

                if(top.first == key)
                    top.second++;
                
                p2.push(top);
            }
            swap(pq,p2);
        }
    }

    void display()
    {
        for(auto it : hash)
        {
            cout<<it<<" ";
        }
        cout<<endl;

        cout<<"LFU Element is : "<<pq.top().first<<" "<<pq.top().second<<endl;
    }

};

int main()
{
    LFU obj (3);
    obj.insert(1);
    obj.insert(2);
    obj.insert(3);

    obj.insert(1);
    obj.insert(2);

    obj.display();      // (3,1) , (2,2) , (1,2)

    obj.insert(5);
    obj.display();      // ( 5,1 ), (2,2) , (1,2)

    obj.insert(1);
    obj.insert(5);
    obj.display();      // (5,2) , (2,2) , (1,3)

    obj.insert(7);
    obj.display();      // (7,1) , (2,2) , (1,3)
}