#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution_BF {
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
                } else if( nums[j] - base_number_i == 1  ||  base_number_i  - nums[j]  == 1  ){
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


class Solution{
public:
    
    int findLHS(vector<int>& nums){
        
        
        unordered_map<int,int> mp;
        
        if(nums.empty())
            return 0;
            
            
        for(int num : nums){
            mp[num]++;
        }
        
        int max_len=0;
        

        for(int j=0; j<nums.size(); j++){
            int x = nums[j];
            if (mp.count(x+1)){
                int pot_max_len = mp[x]+mp[x+1];
                max_len = max(max_len,pot_max_len);
            }
            
        }
        

        
        return max_len;
            
        
        
        
    }
    
    
    
    
};





int main() {
    Solution sol;
    vector<int> nums = {1,3,2,2,5,2,3,7};
    cout << "The longest harmonious subsequences is : " << sol.findLHS(nums);
    
    return 0;
}
