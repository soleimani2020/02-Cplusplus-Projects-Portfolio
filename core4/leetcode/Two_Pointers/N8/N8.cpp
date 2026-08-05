class Solution {
public:

    void swap(int& x, int& y){
        int temp = x;
        x = y ;
        y = temp;
    }


    void reverse(vector<int>& nums, int left, int right){
        while(left<right){
            swap(nums[left],nums[right]);
            left++;
            right--;
        }
    }
    


    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        if(n==0 || k==0) return;
        
        k = k % n;   // to take care of PBC ! 
        
        // Step 1: Reverse entire array
        reverse(nums, 0, n - 1);
        
        // Step 2: Reverse first k elements
        reverse(nums, 0, k - 1);
        
        // Step 3: Reverse remaining elements
        reverse(nums, k, n - 1);
    }
};
