// https://www.geeksforgeeks.org/minimize-cash-flow-among-given-set-friends-borrowed-money/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;
#define Pair pair<int,int> 

class Solution{
private: 
    int N;
    vector<vector<int>> graph;

    int getMin(vector<int> arr){
        int minInd = 0;
        for (int i = 1; i < N; i++)
            if (arr[i] < arr[minInd])
                minInd = i;
        return minInd;
    }
    
    int getMax(vector<int> arr){
        int maxInd = 0;
        for (int i = 1; i < N; i++)
            if (arr[i] > arr[maxInd])
                maxInd = i;
        return maxInd;
    }
    
    
    void minCashFlowRec(vector<int> amount){
        int mxCredit = getMax(amount), mxDebit = getMin(amount);
    
        if (amount[mxCredit] == 0 && amount[mxDebit] == 0)
            return;
        
        int minOf2 = min(-amount[mxDebit], amount[mxCredit]);
        amount[mxCredit] -= minOf2;
        amount[mxDebit] += minOf2;
    
        cout<<"Person "<<mxDebit<<" pays "<<minOf2<<" to Person "<<mxCredit<<endl;
    
        minCashFlowRec(amount);
    }

    void helper(priority_queue<Pair, vector<Pair>, greater<Pair>> minQueue, priority_queue<Pair, vector<Pair>> maxQueue) {

        while(!minQueue.empty() && !maxQueue.empty()) {
            Pair maxCredit = maxQueue.top();
            maxQueue.pop();

            Pair maxDebit = minQueue.top();
            minQueue.pop();

            int transaction = maxCredit.second + maxDebit.second;
            int debtor = maxDebit.first, creditor = maxCredit.first, owedAmt = 0;

            if(transaction == 0)
                owedAmt = maxCredit.second;

            else if(transaction < 0) {
                owedAmt = maxCredit.second;
                minQueue.push({maxDebit.first, transaction});
            }
            else {
                owedAmt = -maxDebit.second;
                maxQueue.push({maxCredit.first, transaction});
            }

            cout<<"Person "<<debtor<<" pays "<<owedAmt<<" to Person "<<creditor<<endl;
        }
    }
    

public:

    Solution(vector<vector<int>> arr) {
        this->N = arr.size();
        graph = arr;
    }

    // Brute Force TC : O(N^2)  & SC : O(N)
    void minCashFlow(){
        vector<int> amount(N,0);
    
        // The value of amount[i] can be calculated by subtracting 
        // debts of 'i' (graph[i][j]) from credits of 'i' (graph[i][p])
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++)
                amount[i] += (graph[j][i] - graph[i][j]);    
        }
        
        minCashFlowRec(amount);
    }


    // Optimized TC : O(NLogN) & SC : O(N)
    void minCashFlow2(){
        vector<int> amount(N,0);
    
        // The value of amount[i] can be calculated by subtracting 
        // debts of 'i' (graph[i][j]) from credits of 'i' (graph[i][p])
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++)
                amount[i] += (graph[j][i] - graph[i][j]);    
        }
        
        priority_queue<Pair, vector<Pair>, greater<Pair>> minQueue;
        priority_queue<Pair, vector<Pair>> maxQueue;

        for(int i=0; i<amount.size(); i++) {
            if(amount[i] == 0)
                continue;
          
            if(amount[i] > 0)
                maxQueue.push({i, amount[i]});
            else
                minQueue.push({i, amount[i]});
        }

        helper(minQueue, maxQueue);
    }
};

int main (){
    vector<vector<int>> graph = { 
        {0, 1000, 2000},
        {0, 0, 5000},
        {0, 0, 0}
    };

    
    Solution s(graph);


    cout<<"Using brute force : "<<endl;
    s.minCashFlow();

    cout<<"\nUsing optimized approach : "<<endl;
    s.minCashFlow2();
}
