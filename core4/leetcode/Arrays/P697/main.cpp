#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
       
        unordered_map<int,vector<int>> mp;  // int: number → vector:{count, first_index, last_index}
       
        for(int index=0 ; index < nums.size(); index++){
            int x = nums[index];
            if(mp.count(x)){
                mp[x][0]++;        // increment count
                mp[x][2] = index;  // update last index
            } else{
                mp[x] = {1, index, index}; // first occurrence
            }
        }
       
       
        int degree = 0;
        for(const auto& entry  : mp){
            if (entry.second[0]  > degree){
                degree = entry.second[0];
            }
        }
       
        int minLength = nums.size();
        for(const auto& entry  : mp){
            if(entry.second[0] == degree){
                int pot_minLength = entry.second[2] - entry.second[1] + 1;
                if(pot_minLength < minLength){
                    minLength = pot_minLength;
                }
            }
        }
       
        return minLength;
    }
};


int main()
{
    vector<int> nums = {1,2,2,3,1,2,3,2,4,4,6};
    Solution object;
    cout << "Smallest subarray length with the array degree: " << object.findShortestSubArray(nums);
   

}
