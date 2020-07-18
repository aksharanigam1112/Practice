#include<iostream>
using namespace std;

void print(int arr[4])
{
    for(int i=0;i<4;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void all4DigitNos(int arr[4][3] , int r , int c , int pos , int total , int temp[4])
{
    if(r<0 || c<0 || r>3 || c>2 || arr[r][c]<0)
        return;

    temp[pos++] = arr[r][c];
    if(pos == total)
    {
        print(temp);
        return;
    }
    
    all4DigitNos(arr,r+1,c,pos,total,temp);
    all4DigitNos(arr,r-1,c,pos,total,temp);
    all4DigitNos(arr,r,c+1,pos,total,temp);
    all4DigitNos(arr,r,c-1,pos,total,temp);
}

int main()
{
    int arr[4][3] = { 
            {1,2,3},
            {4,5,6},
            {7,8,9},
            {-1,0,-1}};

    
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<3;j++)
        {
            int temp[4];
            if(arr[i][j]>=0)
                all4DigitNos(arr,i,j,0,4,temp);
        }
    }
}