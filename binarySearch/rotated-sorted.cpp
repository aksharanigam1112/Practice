// Return the position of the element from an array which is rotated from unknown pivot
// [0,1,2,4,5,6,7] has become [4,5,6,7,0,1,2]
// now to search 4 it should return 4; 

#include<iostream>
#include<vector>
using namespace std;

    int search(vector<int>& nums, int target) 
    {
        int start=0, end = nums.size()-1,mid;

        while(start<=end)
        {
            mid = (start+end)/2;
            
            if(nums[mid] == target)
                return mid;
            
            else if(nums[mid]>=nums[start])
            {
                if(target<=nums[mid] && target>=nums[start])
                    end = mid-1;
                else
                    start = mid+1;
            }
            else if(nums[mid]<=nums[end])
            {
                if(target>=nums[mid] && target<=nums[end])
                        start = mid+1;
                else
                    end = mid-1;
            }
        }
        return -1;
    }

int main()
{
    vector<int> v = {4,5,6,7,0,1,2};
    int target = 3;
    int posOfRotation = 4;
    int ans = search(v,target) ;
    ans = ans!=-1 ? ans+posOfRotation : -1;
    cout<<"Element is at :- "<<ans<<endl;
}