// You have a single-threaded CPU that can process at most 1 task at a time and 
// will act in the following way:
// 1) If the CPU is idle and there are no available tasks to process, the CPU remains idle.
// 2) If the CPU is idle and there are available tasks, the CPU will 
// choose the one with the shortest processing time. If multiple tasks have the same shortest 
// processing time, it will choose the task with the smallest enqueue time.
// 3) Once a task is started, the CPU will process the entire task without stopping.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define p pair<int,int>

vector<int> getOrder(vector<vector<int>>& tasks) 
{     
    priority_queue<p, vector<p>, greater<>> pq; 
    
    int time = 0, i = 0;
        
    for(int j=0; j<tasks.size(); j++) 
        tasks[j].push_back(j); 
    
    sort(tasks.begin(), tasks.end());

    vector<int> ans;
    
    while(i<tasks.size() || pq.size()) 
    { 
        if (pq.empty()) 
            time = max(time, tasks[i][0]); 

        while (i <tasks.size() && time >= tasks[i][0]) 
        {
            pq.push({tasks[i][1], tasks[i][2]});
            i++;
        }
        
        auto it = pq.top();
        pq.pop();
        time += it.first; 
        ans.push_back(it.second);
    }
    return ans;   
}

int main()
{
    vector<vector<int>>q = {{1,2},{1,20},{2,4},{3,2},{4,1}};

    vector<int>ans = getOrder(q);

    for(auto it : ans)
        cout<<it<<" ";
    cout<<endl;
}