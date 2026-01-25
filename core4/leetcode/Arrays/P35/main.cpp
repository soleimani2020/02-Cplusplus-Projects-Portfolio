#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        if (nums.empty()) return -1;
        
        
        int low=0;
        int high = nums.size()-1;

        while(low<=high){
            
            int mid = low + (high-low)/2;
            
            if (target == nums[mid])
                return mid;
                
            else if (target>nums[mid])
                low = mid+1;
                
            else 
                high = mid-1;
            
        }
        
        // If not found, low is the insertion index
        return low;
        
        
    }
};





int main()
{   
    Solution object;
    
    vector<int> nums = {1,3,5,6};
    int target = 5;
    int R = object.searchInsert(nums,target);
    cout << "The index is :" << R;
    return 0;
}
