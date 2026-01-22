class Solution:
    
    def RemoveElement(self, nums, val):
        if not nums:
            return 0
            
        k = 0
        
        for i in range(len(nums)):
            if nums[i] != val:
                nums[k] = nums[i]
                k += 1 
        
        return k


if __name__ == "__main__":
    nums = [0, 1, 2, 2, 3, 0, 4, 2]
    val = 2  # value to remove
    
    obj = Solution()
    K = obj.RemoveElement(nums, val)
    
    print(f"Number of elements after removing {val}: {K}")
    print("New array:", nums[:K])

