class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        
        # Handle edge cases
        if n == 0 or k == 0:
            return
        
        # If k > n, reduce it
        k = k % n
        
        # Step 1: Reverse entire array
        nums.reverse()
        
        # Step 2: Reverse first k elements
        nums[:k] = reversed(nums[:k])
        # OR: nums[:k] = nums[:k][::-1]
        
        # Step 3: Reverse remaining elements
        nums[k:] = reversed(nums[k:])
        # OR: nums[k:] = nums[k:][::-1]
