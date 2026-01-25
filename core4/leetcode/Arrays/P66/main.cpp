#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // Start from the last digit and propagate carry
        for (int i = digits.size() - 1; i >= 0; i--) {
            digits[i] += 1;
            if (digits[i] != 10) {
                // No carry, done
                return digits;
            }
            digits[i] = 0;  // Carry to the next left digit
        }

        // All digits were 9, insert 1 at the front
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main() {
    Solution object;
    
    // Test input
    vector<int> nums = {9, 9, 9};
    // vector<int> nums = {1, 2, 3};
    
    vector<int> R = object.plusOne(nums);
    
    cout << "The new array is: ";
    
    // Print vector with commas
    for (size_t i = 0; i < R.size(); i++) {
        if (i > 0) cout << ", ";
        cout << R[i];
    }
    cout << endl;

    return 0;
}
