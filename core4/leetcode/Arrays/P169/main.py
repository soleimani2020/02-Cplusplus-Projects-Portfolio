class Solution:
    
    def majorityElement(self,nums):
        
        candidate = nums[0]
        count = 1 
        
        for i in range(1,len(nums)):
            if count==0:
                candidate = nums[i]
                count=1 
            
            if nums[i]==candidate:
                count+=1 
            else:
                count-=1 
                
        
        return candidate
        
    

        

if __name__ == "__main__":
    nums = [2,2,1,1,1,3,3,3,3,3]
    
    solution = Solution()
    result = solution.majorityElement(nums)
    
    print(f"Mejority Number (from Boyer-Moore Voting Algorithm method) : {result}")

