#include<iostream>
#include<bits/stdc++.h>
#include<iterator>
#include<algorithm>
using namespace std;

//BRUTE FORCE O(4^L)

bool CrossWord(char crossword[5][4] , char str[4] , int pos , int i , int j , int RS , int CS , int strlen)
{
    if(i<0 || i>=RS || j<0 || j>CS || pos>strlen)
        return false;
    // if(pos == strlen)
    //         return true;
    bool down = CrossWord(crossword,str,pos+1,i+1,j,RS,CS,strlen);
    bool up = CrossWord(crossword,str,pos+1,i-1,j,RS,CS,strlen) ;
    bool right = CrossWord(crossword,str,pos+1,i,j+1,RS,CS,strlen);
    bool left = CrossWord(crossword,str,pos+1,i,j-1,RS,CS,strlen);
    if(down || up || right || left)
        return true;
    else
        return false;
}

//OPTIMIZED O(3^L)

// bool ifExistsinPath(int x ,map<int,int>path)
// {
//     if(path.find(x)->second)
//         return true;
//     return false;
// }

// bool CrossWord(char crossword[5][4] ,map<int,int>path, char str[4] , int pos , int i , int j , int RS , int CS , int strlen)
// {
//     if(i<0 || i>=RS || j<0 || j>CS || !ifExistsinPath(i*CS+j,path) )
//         return false;
//     if(pos == strlen)
//     {
//         path.insert(make_pair(i*CS+j ,1));
//         return true;
//     }

//     bool v1 = CrossWord(crossword,path,str,pos+1,i+1,j,RS,CS,strlen);
//     bool v2 = CrossWord(crossword,path,str,pos+1,i-1,j,RS,CS,strlen);
//     bool v3 = CrossWord(crossword,path,str,pos+1,i,j+1,RS,CS,strlen);
//     bool v4 = CrossWord(crossword,path,str,pos+1,i,j-1,RS,CS,strlen);

//     path.erase(i*CS+j);
//     return(v1 || v2 || v3 ||v4);
// }



int main()
{
    char crossword[5][4] = {{'U' ,'G' , 'C','I'},
                        {'A' ,'K' , 'I','P'},
                        {'R' ,'K' , 'T','T'},
                        {'A' ,'N' , 'E','C'},
                        {'A' ,'N' , 'O','T'}};


    char str[4] = {'R','A','N','K'};

    cout<<CrossWord(crossword,str,0,0,0,5,4,4)<<endl;

    // map<int,int>path;
    // cout<<CrossWord(crossword,path,str,0,0,0,5,4,4);
}
