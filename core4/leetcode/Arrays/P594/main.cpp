#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int maxLen = 0;
        for(int i=0; i< nums.size() ; i++){
            int base_number_i = nums[i];
            int currentLen = 0;        // count for this base number
            bool hasDiff = false;      // flag to check difference of 1 exists
            for(int j=0; j < nums.size(); j++){
                if(nums[j] == base_number_i){
                    currentLen++;
                } else if( abs(nums[j] - base_number_i) == 1 ){
                    currentLen++;
                    hasDiff=true;
                    
                }
            }
            
            if(hasDiff) {
                maxLen = max(maxLen, currentLen);
            }
        }
        return maxLen;
    }
};





int main() {
    Solution sol;
    vector<int> nums = {1,3,2,2,5,2,3,7};
    cout << "The longest harmonious subsequences is : " << sol.findLHS(nums);
    
    return 0;
}
