#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int RemoveElement(vector<int>& nums, int val) {
        if (nums.empty()) return 0;

        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};

int main() {
    Solution object;
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;

    int k = object.RemoveElement(nums, val);
    cout << "K is: " << k << endl;

    cout << "New nums: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}














