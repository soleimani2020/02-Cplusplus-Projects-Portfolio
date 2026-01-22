#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution_BF{
public:
   
    vector<int> TwoSum(vector<int>& nums, int target){
        vector<int> res(2);
        for(int i=0; i<nums.size();i++){
            for(int j=i+1; j<nums.size();j++){
                if (nums[i]+nums[j]==target){
                    res[0]=i;
                    res[1]=j;
                    return res;

                }
            }
 
        }
       
        return {}; // no solution found   
    }
 
};


class Solution{
public:
   
    vector<int> TwoSum(vector<int>& nums, int target){
        unordered_map<int,int> mp;
        vector<int> res(2);
       
        for(int i=0; i<nums.size();i++){
            int complement = target - nums[i];
            if(mp.count(complement)){
                res[0]=mp[complement];
                res[1]=i;
                return res; // Not forget to return the found pair
            }
           
            mp[nums[i]]=i;  // value and index
 
        }
       
        return {}; // no solution found
   
    }
 
};




int main()
{
    Solution object;
   
    vector<int> nums = {2,7,20,30};
   
    int target= 9;
   
   
    // vector can not be directly printed !
    vector<int> result = object.TwoSum(nums,target);
   
   
    // Can not check with boolain : .empty should be used
    if(!result.empty()){
        cout << result[0] << "  "<< result[1];
     }else{
         cout << "No solution found !";
     }



    return 0;
}



