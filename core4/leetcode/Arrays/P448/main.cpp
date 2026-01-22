#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Brut Force Approach 

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        vector<int> result;
        vector<int> nums2;
        
        sort(nums.begin(), nums.end());
        
        // remove duplicates
        for(int num: nums){
            if (nums2.empty()  || num != nums2.back()){
                nums2.push_back(num);
            }
        }
        
        

        // Mising numbers before the first element 
        for (int x=1; x<nums2[0]; x++){
            result.push_back(x);
        }
        
        
        
        // Missing numbers in between 
        for(int i=1; i<nums2.size();i++){
            if( nums2[i] > nums2[i-1]+1 ){
                for(int x=nums2[i-1]+1 ; x <= nums2[i]-1 ; x++){
                    result.push_back(x);
                }
                
            }
            
        }
        
        // Missing numbers after the last elemnt
        for(int x=nums2.back()+1 ; x <= nums.size(); x++){
            result.push_back(x);
        }
        return  result;
    }
};



// in-place marking trick Approach

class Solution2 {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        vector<int> result;
        
        for(int i=0; i<nums.size(); i++){
            int index = abs(nums[i])-1;
            
            if (nums[index] > 0){
            nums[index]=-nums[index];
            }
            
        }
        
        
        
        for(int i=0; i<nums.size();i++){
            if (nums[i]>0){
                result.push_back(i + 1);
            }
        }
        
        return result;
        
 
    }
};



int main() {
    vector<int> nums1 = {4,3,2,7,8,2,3,1}; 

    Solution2 sol;

    vector<int> res = sol.findDisappearedNumbers(nums1);
    
    cout << "Disappeared Numbers:" << endl;
    
    for(int num : res){
        cout << num << " ";
    }
    
    

    return 0;
}


