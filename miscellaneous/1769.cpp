#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> minOperations(string boxes) 
{
    vector<int>ans(boxes.size(),0);
    
    int b=0,sum=0;
    // Move Left to Right
    for(int i=1;i<boxes.size();i++)
    {
        if(boxes[i-1]=='1')
            b++;
        sum += b;
        ans[i] = sum;
    }

    b=sum=0;
    // Move Right to Left
    for(int i=boxes.size()-2;i>=0;i--)
    {
        if(boxes[i+1]=='1')
            b++;
        sum += b;
        ans[i]+=sum;
    }
    return ans;
}

int main()
{
    string boxes = "110";
    vector<int>ans = minOperations(boxes);

    for(auto it : ans)
        cout<<it<<" ";
    cout<<endl;

}