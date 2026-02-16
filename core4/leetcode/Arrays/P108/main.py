class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None
        
    
class Solution:
    def build_bst(self, nums, low, high):
        
        if low > high :
            return 
        
        mid = low + (high - low) // 2
        
        root = Node(nums[mid])
        root.left  = self.build_bst(nums, low, mid - 1)
        root.right = self.build_bst(nums, mid+1, high)
        
        return root
        
    def sorted_array_to_bst(self, nums):
        return self.build_bst(nums, 0, len(nums)-1)
        
        
    def display(self, root):
        if not root :
            return 
        
        self.display(root.left)
        print(root.data, end=" ")
        self.display(root.right)
        
        
        
# ---- Main ----
nums = [-10, -3, 0, 5, 9]

solution = Solution()
root = solution.sorted_array_to_bst(nums)

solution.display(root)
        
        

        
