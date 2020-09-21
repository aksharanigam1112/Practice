#include<iostream>
using namespace std;

int main()
{
    int basic_sal;
    cout<<"Enter basic salary : ";
    cin>>basic_sal;

    try
    {
        if(basic_sal<5000 || basic_sal > 40000)
            throw -1;
        else
        {
            double gross_sal,hra,da;
            if(basic_sal>=5000 && basic_sal<=10000)
            {
                hra = basic_sal*0.2;
                da = basic_sal*0.8;
            }
            else if(basic_sal<=20000)
            {
                hra = basic_sal*0.25;
                da = basic_sal*0.9;
            }
            else
            {
                hra = basic_sal*0.3;
                da = basic_sal*0.95;
            }
            gross_sal = basic_sal + hra + da;
            cout<<"Gross Salary  : "<<gross_sal<<endl;
        }
    }
    catch(int e)
    {
        cout<<"Salary out of range Exception"<<endl;
    }
}