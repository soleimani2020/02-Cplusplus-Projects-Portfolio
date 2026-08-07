#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {

        int n = nums.size();

        // Stores the number of days until a warmer temperature
        vector<int> ans(n, 0);

        // Monotonic decreasing stack storing indices
        stack<int> st;

        // Traverse from right to left
        for(int i = n - 1; i >= 0; i--) {

            // Remove indices whose temperatures are smaller
            // or equal because they cannot be the next warmer day
            while(!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            // If stack is empty, no warmer temperature exists
            if(st.empty()) {
                ans[i] = 0;
            }
            else {
                // Distance between current day and warmer day
                ans[i] = st.top() - i;
            }

            // Store current index for future comparisons
            st.push(i);
        }

        return ans;
    }
};
