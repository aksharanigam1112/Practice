// https://www.geeksforgeeks.org/given-sorted-dictionary-find-precedence-characters/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph{

private:
    map<int, list<int>> adjList;
    map<int, bool> visited;
    stack<char> s;

    void addEdge(char u, char v){
        adjList[u].push_back(v);
    }

    void print(){
        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
        cout<<endl;
    }

    void dfs(char src) {
        visited[src] = true;

        for(auto nbr : adjList[src]) {
            if(!visited[nbr])
                dfs(nbr);
        }
        s.push(src);
    }

    void topologicalSort() {
        for(auto i : adjList) {
            if (!visited[i.first])
                dfs(i.first);
        }

        print();
    }


public:
    void getOrder(vector<string>arr) {

        for(int i=0; i<arr.size()-1; i++) {
            string word1 = arr[i], word2 = arr[i+1];

            for(int j=0; j<word1.length() && j<word2.length(); j++){

                if(word1[j] != word2[j]) {
                    addEdge(word1[j], word2[j]);
                    break;
                }
            }
        }

        topologicalSort();
    }    

};


int main() { 
    vector<string> arr = {"baa", "abcd", "abca", "cab", "cad"};

    Graph g;        
  
    cout<<"Alien dictionary charcter order :"<<endl;
    g.getOrder(arr);
}
