class Solution:
    def findLHS(self,nums):
        if not nums:
            return 0 
            
        mp = {}
        
        for num in nums:
            if num in mp:
                mp[num]+=1 
            else:
                mp[num]=1 
            
            
        max_len=0
        
        for i in range(len(nums)):
            x = nums[i]
            if x+1 in mp:
                pot_max_len = mp[x]+mp[x+1]
                max_len = max(max_len,pot_max_len)
                
        return max_len 
        
        
                
            





nums = [1,3,2,2,5,2,3,7]
sol= Solution()
print("The longest harmonious subsequences is : " , sol.findLHS(nums))



