// https://leetcode.com/problems/interval-list-intersections/description/
#include<iostream>
#include<bits/stdc++.h>
#define Pair pair<int,int>
using namespace std;

vector<Pair> intervalIntersection(vector<Pair> firstList, vector<Pair> secondList) {
	vector<Pair> ans;
	ans.push_back(firstList[0]);

	int i=1, j=0, curr = 0;


	return ans;
}


int main() {
	vector<Pair> firstList = {{0,2},{5,10},{13,23},{24,25}};
	vector<Pair> secondList = {{1,5},{8,12},{15,24},{25,26};

	vector<Pair> ans = intervalIntersection(firstList, secondList);

	for(Pair p : ans){
		cout<<"("<<p.first<<","<<p.second<<"),";
	}
	cout<<endl;
}
