#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution_Hash {
public:
    int majorityElement(vector<int>& nums) {
        
        unordered_map<int,int> mp; // number-->freq
        
        
        for(int i=0; i< nums.size(); i++){
            if(mp.count(nums[i])){
                mp[nums[i]]++;
            }else{
                mp[nums[i]]=1;
            }
        }

        
        
        int max_freq=0;
        int most_frequent=nums[0];
        
        for(int i=0; i< nums.size(); i++){
            
            if( mp[nums[i]] > max_freq ){
                max_freq = mp[nums[i]];
                most_frequent = nums[i];
            }
        }
        
        return most_frequent;
        
        
        
    }
};



class Solution_Hash2 {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp; // number → frequency
        int max_freq = 0;
        int most_frequent = nums[0];
        
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;  // increment frequency
            
            // Update most frequent number on the fly
            if(mp[nums[i]] > max_freq){
                max_freq = mp[nums[i]];
                most_frequent = nums[i];
            }
        }
        
        return most_frequent;
    }
};


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int count = 1;

        for (int i = 1; i < nums.size(); i++) {
            // If current candidate has no support, pick a new candidate
            if (count == 0) {
                candidate = nums[i];
            }

            // Increment or decrement count
            if (nums[i] == candidate) {
                count++;
            } else {
                count--;
            }
        }

        return candidate;
    }
};


int main(){
    
    vector<int> nums = {2,2,1,1,1,3,3,3,3,3};
    
    Solution_Hash object;
    
    cout << "Mejority Number (from hash method): " << object.majorityElement(nums) << endl;
    

    Solution object2;
    
    cout << "Mejority Number (from Boyer-Moore Voting Algorithm method): " << object2.majorityElement(nums) << endl;
    
    
    
    
}
