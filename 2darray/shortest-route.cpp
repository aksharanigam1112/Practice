// Find shortest oute in a grid starting from 0,0 to M-1,N-1
#include<iostream>
#include<vector>
using namespace std;
#define M 3
#define N 3

void print(vector<int>&ans)
{
    for(auto it : ans)
        cout<<it<<" --> ";
}

void smallRoute(int arr[M][N], vector<int>&ans, int i, int j)
{
    if(i==M-1 && j==N-1)
    {
        print(ans);
        cout<<arr[i][j]<<endl;
        return;
    }

    ans.push_back(arr[i][j]);

    if(i<M)
        smallRoute(arr,ans,i+1,j);
    if(j<N)
        smallRoute(arr,ans,i,j+1);
    if(i<M && j<N)
        smallRoute(arr,ans,i+1,j+1);
    
    ans.pop_back();
}

int main()
{
    int arr[M][N] = {{1,2,3},
                    {4,5,6},
                    {7,8,9}};
    vector<int>ans;
    smallRoute(arr,ans,0,0);
}