// Implement a basic calculator to evaluate a simple expression string.
// The expression string may contain open ( and closing parentheses ), 
// the plus + or minus sign -, non-negative integers and empty spaces .
#include<iostream>
#include<stack>
#include<string>
using namespace std;

int calculate(string str) 
{
    stack<int>s;
    int operand=0,result=0,sign=1; 

    for(int i=0; i<str.size(); i++) 
    {
        char ch = str[i];
        if(ch>='0' && ch<='9') 
            operand = 10 * operand + (int) (ch - '0');
        else if(ch == '+') 
        {
            result += sign * operand;
            sign = 1;
            operand = 0;
        } 
        else if (ch == '-') 
        {
            result += sign * operand;
            sign = -1;
            operand = 0;
        } 
        else if (ch == '(') 
        {
            s.push(result);
            s.push(sign);   
            sign = 1;
            result = 0;
        } 
        else if (ch == ')') 
        {
            result += sign * operand;

            result *= s.top();
            s.pop();

            result += s.top();
            s.pop();

            operand = 0;
        }
    }
    return result + (sign * operand);
}

int main()
{
    string str = "123+5";
    cout<<"Ans of the expression : "<<calculate(str)<<endl;
}