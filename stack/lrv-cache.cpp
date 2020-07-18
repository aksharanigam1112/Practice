#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class cache
{
    private : 
    
    void printCache(multimap<int,double>MM)
    {
        cout<<"\nDocID Cost"<<endl;
        for (auto it : MM) 
        { 
            cout<<it.second<<"\t"<< it.first<< endl; 
        } 
    }
    
    public:
    map<int,vector<int>>document;
    map<int,double>lrv;

    void insert(int docId, int cost, int size, int lastRefTime)
    {
        document[docId].push_back(cost);
        document[docId].push_back(size);
        document[docId].push_back(lastRefTime);
        lrv[docId] = (cost*size/lastRefTime);
    }

    void docAccess(int doc, int time)
    {
        document[doc][2] = time;
        lrv[doc] = document[doc][0]*document[doc][1]/time;
        rankCache();
    }

    void rankCache()
    {
       multimap<int, double> MM; 

        for (auto it : lrv) 
        { 
            MM.insert({ it.second, it.first }); 
        } 
        printCache(MM);
    }

    void remove()
    {
        int least = INT_MAX;
        map<int,double>::iterator it, index;

        for(it=lrv.begin();it!=lrv.end();it++)
        {
            if((*it).second < least)
            {
                least = (*it).second;
                index = it;
            }
        }
        lrv.erase(index);
    }
};

int main()
{
    cache obj;
    obj.insert(1,5,15,1);
    obj.insert(2,1,5,2);
    obj.insert(3,10,20,5);
    obj.insert(4,6,7,9);
    
    cout<<"Original cache : \n";
    obj.rankCache();

    cout<<"After accessing a doc : \n";
    obj.docAccess(1,5);

    obj.remove();
    cout<<"\nAfter removing least relative value element the cache is : \n";
    obj.rankCache();
}