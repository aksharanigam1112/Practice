#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class cache
{
    public:
        int size;
        queue< pair<int,int> >lru;
        map<int,int>hash;
        cache(int s)
        {
            size = s; 
        }
        void set(vector<int>num)
        {
            if(lru.size()<size)
            {
                lru.push(make_pair(num[0],num[1]));
                hash.insert(make_pair(num[0],num[1]));
            }
            else
            {
                lru.pop();
                lru.push(make_pair(num[0],num[1]));
                hash.insert(make_pair(num[0],num[1]));
            }
        }
        int get(int x)
        {
            if(hash.find(x)->second)
                return(hash.find(x)->second);
             else
                return -1;         
        }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;

        cache obj(n);

        
        string query;

        for(int i=0;i<q;i++)
        {
            cin>>query;
            if(query.find('SET'))
            {
                vector<int> num(2);
                for (int i=0; i<query.length(); i++) 
                { 
                     if (isdigit(query[i])) 
                        num.push_back(query[i]); 
                }
                obj.set(num);
            }
            else
            {
                int num;
                for (int i=0; i<query.length(); i++) 
                { 
                     if (isdigit(query[i])) 
                        num = query[i]; 
                }
                cout<<obj.get(num);
            }
             
        } 
    }
}