// Leetcode Medium - 1801
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pr pair<int,ll>


ll m = pow(10,9)+7;
int count(priority_queue<pr>&buy, priority_queue<pr,vector<pr>,greater<pr>>&sell)
{
    ll c=0;
    // cout<<"Buy backlog : ";
    while(!buy.empty())
    {
        // cout<<"Price : "<<buy.top().first<<" Quantity : "<<buy.top().second<<endl;
        c+=buy.top().second;
        buy.pop();
    }

    // cout<<"Sell Backlog : ";
    while(!sell.empty())
    {
        // cout<<"Price : "<<sell.top().first<<" Quantity : "<<sell.top().second<<endl;
        c+= sell.top().second;
        sell.pop();
    }
    return c%m;
}


int getNumberOfBacklogOrders(vector<vector<int>>& orders) 
{
    // Max heap
    priority_queue<pr> buy;

    // Min heap
    priority_queue<pr,vector<pr>,greater<pr>>sell;


    for(int i=0;i<orders.size();i++)
    {
        int p = orders[i][0], type = orders[i][2]; ll quantity = orders[i][1];
        
        //  Buy
        if(type==0)
        {
            if(sell.empty() || sell.top().first>p)
            {
                buy.push({p,quantity});
                continue;
            }
            
            while(quantity>0 && !sell.empty() && sell.top().first <= p)
            {
                auto it = sell.top();
                sell.pop();
                    
                if(quantity<=it.second)
                {
                    it.second-=quantity;
                    sell.push({it.first,it.second});
                    break;
                }
                else
                    quantity-=it.second;
            }
            if(sell.empty() || sell.top().first > p)
                buy.push({p,quantity});
        }
            
        // Sell
        if(type==1)
        {
            if(buy.empty() || buy.top().first<p)
            {
                sell.push({p,quantity});
                continue;
            }
            
            while(quantity>0 && !buy.empty() && buy.top().first >= p)
            {
                auto it = buy.top();
                buy.pop();

                if(quantity<=it.second)
                {
                    it.second-=quantity;
                    buy.push({it.first,it.second});
                    break;
                }
                else
                    quantity-=it.second;
            }
            if(buy.empty() || buy.top().first < p)
                sell.push({p,quantity});   
        }
    }
    return count(buy,sell);
}

int main()
{
    vector<vector<int>> orders ={{26,7,0},{16,1,1},{14,20,0},{23,15,1},{24,26,0},{19,4,1},{1,1,0}};
    cout<<"No. of backlogs are : "<<getNumberOfBacklogOrders(orders)<<endl;
}