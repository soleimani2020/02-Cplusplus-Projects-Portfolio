#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;


class Solution {
public:

    int arrayPairSum(vector<int>& nums){
       
        if(nums.empty()) return 0;
       
        sort(nums.begin(),nums.end());   // O(n log n)
       
       
        int sum=0;
        for(int i=0; i<nums.size(); i += 2){
            sum+=nums[i];
        }
       
        return sum;
    }

};





int main(){
   
    vector<int> nums = {1,4,3,2};
   
    Solution object;
   
    cout << "Maximum of sum of Mins is:" << object.arrayPairSum(nums);
   
   
   
}
