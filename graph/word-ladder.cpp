// Given two words, and a dictionary's word list, 
//find the length of shortest transformation sequence from beginWord to endWord 
// such that: 1) Only one letter can be changed at a time. 
// 2) Each transformed word must exist in the word list.
#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

void differentWord(string start, set<string>&dict, queue<string>&bfs, map<string,string>&visited)
{
    for(auto it : dict)
    {
        int i=0,j=0,l1=start.length(),l2=it.length();
        if(l1==l2)
        {
            int diff=0;
            while(i<l1 && j<l2 && diff<=1)
            {
                if(start[i]!=it[j])
                    diff++;
                i++;
                j++;
            }
            if(diff==1 && visited.find(it)==visited.end())
            {
                bfs.push(it);
                visited[it]=start;
            }
        }
    }
}

int trace(string target, map<string,string>visited)
{
    int count=0;
    cout<<target<<" , ";
    while(visited[target]!=" ")
    {
        cout<<visited[target]<<" , ";
        target = visited[target];
        count++;
    }
    cout<<endl;
    return count;
}

int ladder(string start, string target, set<string>&dict)
{
    queue<string>bfs;
    map<string,string>visited;

    bfs.push(start);
    visited[start]=" ";
    
    while(!bfs.empty())
    {
        string ele = bfs.front();
        bfs.pop();

        if(ele==target)
            return trace(target,visited);
        differentWord(ele,dict,bfs,visited);
    }
    return -1;
}

int main()
{
    set<string>dict;
    dict.insert("MILK");
    dict.insert("MIND");
    dict.insert("MILD");
    dict.insert("SINK");
    dict.insert("PINK");
    dict.insert("KIND");
    dict.insert("FIND");

    // dict.insert("hot");
    // dict.insert("dot");
    // dict.insert("dog");
    // dict.insert("lot");
    // dict.insert("log");
    // dict.insert("cog");

    string start = "MILD";
    string target = "FIND";
    cout<<"Transformations required : "<<ladder(start,target,dict)<<endl;
}