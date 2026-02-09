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

int main() {
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};

    Solution_BF sol;
    vector<int> R = sol.nextGreaterElement(nums1, nums2);

    for (int num : R) {
        cout << num << " ";
    }

    return 0;
}
