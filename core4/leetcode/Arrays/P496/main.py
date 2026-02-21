class Solution:
    
    def nextGreaterElement(self, nums1, nums2):
        
        mp={}
        stack=[]
        
        for num in reversed(nums2):
            while stack and stack[-1] <= num:
                stack.pop()
            
            if stack:
                mp[num] = stack[-1]
            else:
                
                mp[num] = -1
                
            stack.append(num)
            
        
        # Build result for nums1
        result=[]
        for num in nums1:
            result.append(mp[num])
            
        return result
            
        
    
    
    
    
    
    
    
    
    
    
if __name__ == "__main__":
    nums1 = [4, 1, 2]
    nums2 = [1, 3, 4, 2]

    sol = Solution()
    res = sol.nextGreaterElement(nums1, nums2)
    print(res)  # Output: [-1, 3, -1]
