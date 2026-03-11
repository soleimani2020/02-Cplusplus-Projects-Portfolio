class Solution {
public:
    int maximumProduct(vector<int>& nums) {
       
        if(nums.empty())
            return 0;
           
        sort(nums.begin(),nums.end());
       
        int product1=nums[0]*nums[1]*nums[nums.size()-1];
        int product2=nums[nums.size()-3]*nums[nums.size()-2]*nums[nums.size()-1];
       
        int res = max(product1,product2);
       
        return res;
   
    }
};

class Solution:
    def maximumProduct(self,nums):
        if not nums:
            return 0
           
        nums.sort()
       
        n=len(nums)
       
        product1 = nums[n-1]*nums[n-2]*nums[n-3]
        product2 = nums[n-1]*nums[0]*nums[1]
       
        result = max(product1,product2)
       
        return result
