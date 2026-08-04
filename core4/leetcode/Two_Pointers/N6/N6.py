class Solution:
    def twoSum(self, numbers, target):
        left = 0
        right = len(numbers) - 1
        
        ans = []
        
        while left < right:
            Sum = numbers[left] + numbers[right]
            
            if Sum == target:
                ans.append(left + 1)
                ans.append(right + 1)
                return ans
            
            elif Sum < target:
                left += 1
            
            else:
                right -= 1
        
        return ans
