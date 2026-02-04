#include <iostream>
#include <vector>
#include <algorithm>  // Sort 

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if (nums.empty()) return 0; // empty array, missing 0
        
        sort(nums.begin(), nums.end());
    
        if (nums[0] != 0) return 0; // 0 is missing
    
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i-1] + 1) {
                return nums[i-1] + 1;
            }
        }
    
        return nums.size(); // missing last number
    }
};




int main() {
    vector<int> nums = {3,0,1};

    Solution object;
    cout << "Missing Number is :" << object.missingNumber(nums);

    return 0;
}
