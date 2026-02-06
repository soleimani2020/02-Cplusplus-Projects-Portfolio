#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> result;
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int i = 0;
        int j = 0;
        
        while(i < nums1.size() && j < nums2.size()){
            if (nums1[i] < nums2[j]){
                i++;
            } else if (nums1[i] > nums2[j]){
                j++;
            } else {
                // nums1[i] == nums2[j]
                result.push_back(nums1[i]);
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

    Solution sol;
    vector<int> res = sol.intersect(nums1, nums2);

    cout << "Intersection: ";
    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}


