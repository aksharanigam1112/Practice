// Convert one string to another in min steps by the following operations :-
// 1) Insertion 
// 2) Deletion 
// 3) Replace

#include<iostream>
using namespace std;

int Min(int x , int y , int z)
{
    return min(x,min(y,z));
}

// Brute Force O(3^N)
int editDistanceBF(string str1 , string str2 , int l1 ,  int l2)
{
    // Insert every character
    if(l1 == 0)
        return l2;

    // Remove every character   
    if(l2==0)
        return l1;
    
    if(str1[l1-1] == str2[l2-1])
        return editDistanceBF(str1,str2,l1-1,l2-1);
    else
    {
        int insert = editDistanceBF(str1,str2,l1,l2-1);
        int del = editDistanceBF(str1,str2,l1-1,l2);
        int replace = editDistanceBF(str1,str2,l1-1,l2-1);

        return (1+ Min(insert,del,replace));
    }
}

int editDistanceBU(string str1 , string str2)
{
    int M = str1.length();
    int N = str2.length();

    int dp[M+1][N+1];

    for(int i=0;i<=N;i++)
        dp[0][i]= i;
    for(int i=0;i<=M;i++)
        dp[i][0] = i;

    for(int i=1;i<=M;i++)
    {
        for(int j=0;j<=N;j++)
        {
            if(str1[i] == str2[j])  
                dp[i][j] = dp[i-1][j-1];
        
            else
            {
                int insert = dp[i][j-1];
                int del = dp[i-1][j];
                int replace = dp[i-1][j-1];

                dp[i][j] = (1+ Min(insert,del,replace));
            }
        }
    }
    return dp[M][N];
}

int main()
{
    string str1 = "geeks" , str2 = "gesek";
    int l1 = str1.length() , l2 = str2.length();

    cout<<"Min Steps required BF :- "<<editDistanceBF(str1,str2,l1,l2)<<endl;
    cout<<"Min Steps required BU :- "<<editDistanceBU(str1,str2)<<endl;
}
