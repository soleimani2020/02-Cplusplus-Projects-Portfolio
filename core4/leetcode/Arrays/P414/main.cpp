#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        vector<int> new_arr;
        
        for(int i=0; i< nums.size(); i++){
            if (new_arr.empty() || new_arr.back() != nums[i]){
                new_arr.push_back(nums[i]);
            }
        }
        
        
        
        int n = new_arr.size();
        if (new_arr.size() >= 3){
            return new_arr[n-3];
            
        }else{
            return new_arr[n-1];
        }
        
  
    }
};


class Solution2 {
public:
    int thirdMax(vector<int>& nums) {
        
        long long first = LLONG_MIN;
        long long second = LLONG_MIN;
        long long third = LLONG_MIN;

        for (int num : nums) {
            // Skip duplicates
            if (num == first || num == second || num == third)
                continue;

            if (num > first) {
                third = second;
                second = first;
                first = num;
            } else if (num > second) {
                third = second;
                second = num;
            } else if (num > third) {
                third = num;
            }
        }

        // If third was never updated, return the maximum
        return (third == LLONG_MIN) ? first : third;
    }
};



int main() {
    vector<int> nums1 = {2,2,3,1}; // {2,1}

    Solution sol;

    cout << "Third Max Number is (if it exists ! otherwise you'll see the last element) : " << sol.thirdMax(nums1);

    return 0;
}


