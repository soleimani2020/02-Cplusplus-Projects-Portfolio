class Solution:
    
    def singleNumber(self, nums):
        
        mp = { }  # number ---> freq
        
        
        # Count frequencies
        for num in nums:
            if num in mp:
                mp[num]+=1 
            else:
                mp[num]=1
            
            
        # Find the number with frequency 1
        for num in nums:
            if mp[num]==1:
                return num
                
        
        return 0
        
        

   

if __name__ == "__main__":
    nums = [2,2,1]
    
    solution = Solution()
    result = solution.singleNumber(nums)
    
    print(f"Single Number is : {result}")

