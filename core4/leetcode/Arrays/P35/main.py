class Solution:
    
    def searchInsert(self,nums,target):
        if not nums:
            return 0;
            
        low  = 0
        high = len(nums) - 1
        
        
        while low <= high :
            mid = low + (high-low)//2
            
            if (target == nums[mid]):
                return mid;
                
            elif(target < nums[mid]):
                high = mid-1
                
            elif(target > nums[mid]):
                low = mid+1
                
        return low
                


        




if __name__ == "__main__":
    nums = [1,3,5,6]
    
    target =5
    
    object = Solution()
    
    K = object.searchInsert(nums,target)
    
    print(f"The index is :  {K}")
    

    

    


