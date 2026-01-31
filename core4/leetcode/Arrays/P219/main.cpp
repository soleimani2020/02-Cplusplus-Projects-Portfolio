#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        // Hash map to store the last index where each number appeared
        unordered_map<int,int> mp; // number --> last index
        
        // Loop through the array
        for(int index = 0; index < nums.size(); index++) {
            
            // Check if the current number has been seen before
            if (mp.count(nums[index])) {
                
                // Calculate the distance between current index and last seen index
                int distance = index - mp[nums[index]];
                
                // If the distance is <= k, a nearby duplicate exists
                if (distance <= k) {
                    return true;
                } else {
                    // Update the map with the current index
                    // This ensures the map always holds the latest index of the number
                    mp[nums[index]] = index;
                }
            } else {
                // First time seeing this number, store its index
                mp[nums[index]] = index;
            }
        }
        
        // If no nearby duplicate was found, return false
        return false;
    }
};



int main() {
    vector<int> nums = {1, 2, 3, 1};
    int k = 3;

    Solution object;

    if(object.containsNearbyDuplicate(nums, k)){
        cout << "There is a nearby duplicate!" << endl;
    } else {
        cout << "There is NO nearby duplicate!" << endl;
    }

    return 0;
}
