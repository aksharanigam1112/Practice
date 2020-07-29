// An integer number is given. You have to return next largest no which is a palindrome.
// if the input number is “9 9 9”, the output should be “1 0 0 1”. 
#include<iostream>
#include<math.h>
using namespace std;

void print(int arr[], int size)
{
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

bool checkPalin(int arr[], int size)
{
    int i=0,j=size-1;
    while(i<=j)
    {
        if(arr[i]!=arr[j])
            return false;
        i++;
        j--;
    }
    return true;
}

bool checkAll9(int arr[], int size)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]!=9)
            return false;
    }
    return true;
}

void nextPalindrome(int arr[], int size)
{
    // If it is a Palindrome then 2 cases occur : 
    // 1) All 9's
    // 2) Not all 9's
    if(checkPalin(arr,size))
    {
        if(checkAll9(arr,size))
        {
            cout<<(pow(10,size)+1)<<endl;
            return;
        }
        else
        {
            // Increment the middle digit and propagate the carry to left and right side
            int lp,rp,carry=1;

            if(size%2==0)
            {
                lp = size/2 - 1;
                rp = lp+1;
            }
            else
                lp = rp = size/2;
                
            while(carry && lp>=0 && rp<size && lp<rp)
            {
                int val = arr[lp];
                arr[lp] = (val+carry)%10;
                arr[rp] = (val+carry)%10;
                carry = (val+carry)/10; 
                
                lp--;
                rp++;
            }
            if(lp==rp)
                arr[lp]++;
        }
    }


    // If the no is not palindrome
    else
    {
        int lp,rp;
        if(size%2==0)
        {
            lp = (size/2)-1;
            rp = lp+1;
        }
        else
            lp = rp = size/2;
        
        // Find the index where the digits are not equal
        while(arr[lp]==arr[rp])
        {
            lp--;
            rp++;
        }

        // If left digit is greater than right digit 
        if(arr[lp] > arr[rp])
        {
            // Copy from left to right
            while(lp>=0 && rp<size)
            {
                arr[rp] = arr[lp];
                rp++;
                lp--;
            }
        }

        // If left digit is less than right digit
        else
        {
            // Increment th middle digit digit and propagate the carry both the sides
            // i.e the left side and right side

            int carry = 1,temp1, temp2;
            temp1 = size%2==0 ? (size/2)-1: size/2;
            temp2 = size%2==0 ? temp1+1 : temp1;

            while(carry && temp1>=0 && temp2<size && temp1<=temp2)
            {
                int val = arr[temp1];
                if(temp1==temp2)
                    arr[temp1] = (val+carry)%10;
                else
                {
                    arr[temp1] = (val+carry)%10;
                    arr[temp2] = (val+carry)%10;   
                }
                
                carry = (val+carry)/10; 
                
                temp1--;
                temp2++;
            }
            
            // Copy from left to right from the position where left digit was smaller than right digit
            while(lp>=0 && rp<size)
            {
                arr[rp] = arr[lp];
                rp++;
                lp--;
            }
        }
    }
    print(arr,size);
}

int main()
{
    int arr[] = {9,4,1,8,7,9,7,8,3,2,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Next Larger Palindromic No. : "<<endl;
    nextPalindrome(arr,size);
}