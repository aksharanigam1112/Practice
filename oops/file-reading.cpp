#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream fin;  
    fin.open("sample.txt"); 
    try
    {      
        string line;
        bool  flag = false;
        while (fin) 
        { 
            getline(fin, line); 
            cout << line << endl; 
            flag = true;
        } 
        if(!flag)
            throw flag ;
    }
    catch(bool flag)
    {
        cout<<"File Not found Exception"<<endl;
    }

    fin.close(); 
}