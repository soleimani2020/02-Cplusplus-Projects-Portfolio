#include <iostream>
#include <vector>

using namespace std;

class Solution_BF {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;

        // Loop over each element in nums1
        for (int i = 0; i < nums1.size(); i++) {
            int x = nums1[i];
            bool found = false;

            // Find x in nums2
            for (int j = 0; j < nums2.size(); j++) {
                if (nums2[j] == x) {
                    // Look for the next greater element
                    for (int k = j + 1; k < nums2.size(); k++) {
                        if (nums2[k] > x) {
                            result.push_back(nums2[k]);
                            found = true;
                            break;
                        }
                    }
                    break; // Stop searching nums2 once x is found
                }
            }

            // If no greater element found, push -1
            if (!found) {
                result.push_back(-1);
            }
        }

        return result;
    }
};


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    
    unordered_map<int,int> mp; // nums2[i]--->nextGreaterElement 
    stack<int> s;
    
    
    for(int i=nums2.size()-1 ; i>=0 ;i--){
        
        // Removing irrelavat elements form the stack
        while(!s.empty() && s.top()<= nums2[i]){
            s.pop();
        }
        
        
        if(s.empty()){
            mp[nums2[i]]=-1;
        }else{
            mp[nums2[i]]=s.top();
        }
        
        s.push(nums2[i]);
    }
    
    
    vector<int> ans;
    
    for(int i=0; i<nums1.size();i++){
        ans.push_back(mp[nums1[i]]);
    }
    
    return ans;
 
    }

};

int main() {
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};

    Solution sol;
    vector<int> R = sol.nextGreaterElement(nums1, nums2);

    for (int num : R) {
        cout << num << " ";
    }

    return 0;
}

// ans : {-1,3,-1}

