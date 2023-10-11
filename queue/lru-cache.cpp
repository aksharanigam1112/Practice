#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class LRU {
private:
    map<int,int>hash;
    queue<int> lru;

    void removeLeastRecentlyUsed() {
        int ele = lru.front();      
        lru.pop();
        hash.erase(ele);
    }

    void findAndUpdate(int k) {
        queue<int> temp; 

        while(!lru.empty()) {
            int ele = lru.front();
            lru.pop();

            if(ele != k)
                temp.push(ele);
        }

        lru = temp;
        lru.push(k);
    }

public:
    int capacity;

    LRU(int cap) {
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
            removeLeastRecentlyUsed();
        }

        hash[k] = v;
        lru.push(k);
    }

    void getCache() {
        queue<int> temp = lru;

        cout<<"Key value in order of least recently used : "<<endl;
        while(!temp.empty()) {
            int ele = temp.front();
            cout<<ele<<" : "<<hash[ele]<<endl;
            temp.pop();
        }
    }

};

int main() {

    LRU lru(3);

    cout<<"GET KEY 1 : "<<lru.get(1)<<endl;

    lru.set(1, 10);
    lru.set(2, 20);
    lru.set(3, 30);
    lru.getCache();

    cout<<"GET KEY 1 : "<<lru.get(1)<<endl;
    lru.getCache();

    lru.set(4, 40);
    lru.getCache();

    cout<<"GET KEY 2 : "<<lru.get(2)<<endl;
    cout<<"GET KEY 3 : "<<lru.get(3)<<endl;
    lru.getCache();
}
