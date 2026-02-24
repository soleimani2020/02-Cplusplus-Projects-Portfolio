class Solution:
    def findMaxConsecutiveOnes(self, nums):
        if not nums:
            return 0
        
        max_count = 0
        count = 0
        
        for num in nums:
            if num == 1:
                count += 1
                max_count = max(max_count, count)
            else:
                count = 0
                
        return max_count
        
        
    def findMaxConsecutiveOnes(nums):
        max_count = count = 0
        for num in nums:
            count = count + 1 if num == 1 else 0
            max_count = max(max_count, count)
        return max_count


nums = [1,1,0,1,1,1]
sol = Solution()
print("Maximum Consecutive Ones:", sol.findMaxConsecutiveOnes(nums))
