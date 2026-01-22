class Solution:
    
    def plusOne(self,nums):
        if not nums:
            return {};
        
        
        # Start from the last digit
        for i in range(len(nums)-1, -1, -1):
            nums[i]+=1 
            if nums[i] != 10 :
                return nums 
            nums[i]=0  # carry over
            
        
        # If all digits were 9, create a new list with extra digit
        new_nums = [1] + [0 for num in nums]

        return new_nums



        




if __name__ == "__main__":
    nums = [9, 9, 9]
    object = Solution()
    
    New_nums = object.plusOne(nums)
    
    print("The new array is :",New_nums)
    

    

    


