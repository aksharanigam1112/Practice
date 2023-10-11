#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define Pair pair<int,int> 

struct comp {
    bool operator() (Pair p1, Pair p2) {
        return p1.second > p2.second;
    }
};

class LFU {
private:
    map<int,int>hash;
    priority_queue<Pair, vector<Pair>, comp> lfu;

    void removeLeastFreqUsed() {
        Pair ele = lfu.top();      
        lfu.pop();
        hash.erase(ele.first);
    }

    void findAndUpdate(int k) {
        priority_queue<Pair, vector<Pair>, comp> temp; 
        int freq = 0;

        while(!lfu.empty()) {
            Pair ele = lfu.top();
            lfu.pop();

            if(ele.first != k)
                temp.push(ele);
            else
                freq = ele.second;
        }

        lfu = temp;
        lfu.push({k,freq + 1});
    }

public:
    int capacity;

    LFU(int cap) {
        this->capacity = cap;
    }

    int get(int key) {

        if (hash.find(key) != hash.end()) {

            findAndUpdate(key);
            return hash[key];
        }

        return -1;
    }

    void set(int k, int v) {

        if(hash.find(k) != hash.end()) {
            
            findAndUpdate(k);
            hash[k] = v;
            
            return;
        }


        if(hash.size() == capacity) {
            removeLeastFreqUsed();
        }

        hash[k] = v;
        lfu.push({k,1});
    }

    void getCache() {
        priority_queue<Pair, vector<Pair>, comp> temp = lfu;

        cout<<"Key value in order of least freq used : "<<endl;
        
        while(!temp.empty()) {
            Pair ele = temp.top();
            cout<<ele.first<<" freq : "<<ele.second<<" val = "<<hash[ele.first]<<endl;
            temp.pop();
        }
    }

};

int main() {

    LFU lfu(3);

    cout<<"GET KEY 1 : "<<lfu.get(1)<<endl;

    lfu.set(1, 10);
    lfu.set(2, 20);
    lfu.set(3, 30);
    lfu.getCache();

    cout<<"GET KEY 1 : "<<lfu.get(1)<<endl;
    lfu.getCache();

    lfu.set(4, 40);
    lfu.getCache();

    cout<<"GET KEY 2 : "<<lfu.get(2)<<endl;
    cout<<"GET KEY 3 : "<<lfu.get(3)<<endl;
    lfu.getCache();
}
