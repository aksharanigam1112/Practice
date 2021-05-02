// Given two lists, scores and ages, where each scores[i] and ages[i] 
// represents the score and age of the ith player, 
// respectively, return the highest overall score of all possible basketball teams.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int bestTeamScore(vector<int>& scores, vector<int>& ages) 
{
    vector<pair<int,int>>team ;

    for(int i=0;i<scores.size();i++)
    {
        team.push_back({ages[i],scores[i]});
    }

    sort(team.begin(),team.end());

    int maxScore=INT_MIN;
    int lis[scores.size()] = {0};
    
    for(int i=0;i<scores.size();i++)
    {
        lis[i] = team[i].second;
        
        for(int j=0;j<i;j++)
        {
            if(team[i].second >= team[j].second)
            {
                lis[i] = max(lis[i],lis[j]+team[i].second);
            }
        }
        maxScore = max(maxScore,lis[i]);
    }
    return maxScore;
}
int main()
{
    vector<int>scores = {1,2,3,5};
    vector<int>age = {8,9,10,1};

    cout<<"Max score : "<<bestTeamScore(scores,age)<<endl;
}
