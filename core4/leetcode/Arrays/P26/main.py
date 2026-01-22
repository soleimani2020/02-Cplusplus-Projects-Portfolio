class Solution:
    
    def RemoveDuplicate(self, nums):
        
        if not nums:
            return  0;
            
        replace = 1;
        
        for i in range(1,len(nums)):
            if nums[i-1] != nums[i]:
                nums[replace] = nums[i];
                replace+=1 
        
        return replace
    
    

if __name__ == "__main__":
    nums = [5,6,7,7,7,8]
    
    solve = Solution()
    
    R = solve.RemoveDuplicate(nums)
    
    print(f"Number of unique elements is: {R}")
    print("New array:", nums[:R])
    



