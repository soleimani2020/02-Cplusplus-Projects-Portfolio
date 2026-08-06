#include <stack>

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        
        
        int n = nums.size();
        vector<int> ans(n, 0);
        stack<int> st;  // stores indices
        
        
        for(int i=n-1; i>=0 ; i--){
            
            int x = nums[i];
            
            
            // remove useless warmer days
            while(! st.empty() && nums[st.top()] <= x){
                st.pop();
            }
            
            // if stack not empty, top is next warmer day
            if (!st.empty()) {
                ans[i] = st.top() - i;
            }
            
            st.push(i);

            
            
            
        }
        
        return ans;
        
        
        
        
        
    }
};
