#include <iostream>
#include <vector>
#include <unordered_map>  
#include <algorithm>

using namespace std;

class Solution_Hash {
public:

    
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        
        vector<int> result;
        unordered_map<int,bool> mp; // number ---> existance
        
        
        for(int num : nums1){
            mp[num]=true;  // not added to the result yet
        }
        
        for(int num : nums2){
            if (mp.count(num) && mp[num]==true){
                result.push_back(num);
                mp[num]=false;
            }
        }
        
        return result;
        
    }
      
};


class Solution_Sort {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        
        // Step 1: Sort both arrays
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        // Step 2: Initialize pointers
        int i = 0, j = 0;
        
        // Step 3: Traverse both arrays
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else { // nums1[i] == nums2[j]
                // Avoid duplicates in the result
                if (result.empty() || result.back() != nums1[i]) {
                    result.push_back(nums1[i]);
                }
                i++;
                j++;
            }
        }
        
        return result;
    }
};





int main() {
    vector<int> nums1 = {1, 2, 2, 1, 3};
    vector<int> nums2 = {2, 2 , 3};

    Solution_Sort sol;
    vector<int> res = sol.intersection(nums1, nums2);

    cout << "Intersection: ";
    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}


