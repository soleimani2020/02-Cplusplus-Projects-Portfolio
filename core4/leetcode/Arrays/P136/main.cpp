#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution_Hash {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;  // number -> frequency
        
        for(int i=0; i< nums.size(); i++){
            if (mp.count(nums[i])){
                
                // increment the frequency if number exists
                mp[nums[i]]++;
            }else{
                mp[nums[i]]=1;
            }
        }
        
        
        for(int i=0; i<nums.size(); i++){
            if (mp[nums[i]]==1){
                return nums[i];
            }
        }
        
        return -1; // no valid solution
        
 
    }
};



class Solution{
public:
    
    int singleNumber(vector<int>& nums) {
        
        int result = 0;
        for(int i=0; i<nums.size();i++){
            result^=nums[i];
        }
        
        return result;
    }
}; 



int main(){
    
    vector<int> nums = {2,2,1};
    
    Solution_Hash object;
    
    cout << "single Number (from hash method): " << object.singleNumber(nums) << endl;
    

    Solution object2;
    
    cout << "single Number (from XOR method): " << object2.singleNumber(nums) << endl;
    
    
    
    
}
