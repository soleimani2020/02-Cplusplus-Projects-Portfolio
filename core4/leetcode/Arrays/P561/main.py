class Solution:
   
    def arrayPairSum(self,nums):
        if not nums:
            return 0
           
        nums.sort()
   
        sum=0
        for i in range(0,len(nums), 2):
            sum+=nums[i]
           
           
        return sum
       


nums = [1,4,3,2]

sol = Solution()
print("Maximum of sum of Mins is:",sol.arrayPairSum(nums))



