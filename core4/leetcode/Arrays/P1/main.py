class Solution_BF:
    
    def two_sum(self, nums, target):
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[i] + nums[j] == target:
                    return [i, j]
        return []  # no solution found
        
        
        
class Solution:

    def two_sum(self, nums, target):
        mp = {}  # dictionary to store value -> index

        for i in range(len(nums)):
            complement = target - nums[i]

            if complement in mp:
                return [mp[complement], i]  # return indices

            mp[nums[i]] = i  # store value and index

        return []  # no solution found


if __name__ == "__main__":

    nums = [2, 7, 11, 15]
    target = 9

    solver = Solution()
    result = solver.two_sum(nums, target)

    if result:
        print("Indices:", result)
        print("Values:", nums[result[0]], "+", nums[result[1]], "=", target)
    else:
        print("No solution found.")

