#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int streak=0;
        int max_streak=0;
        
        for(int i=0; i<nums.size();i++){
            if (nums[i]==1){
                streak++;
                if (streak > max_streak){
                    max_streak = streak;
                }
            }else{
                streak = 0;
            }
        }
        
        return max_streak;
        
    }
};


int main() {
    vector<int> nums = {1,1,0,1,1,1};

    Solution sol;
    
    cout << "Maximum Consecutive Ones : " << sol.findMaxConsecutiveOnes(nums) << endl;

    return 0;
}
