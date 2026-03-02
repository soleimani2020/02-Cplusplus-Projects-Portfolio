class Solution:
    def distributeCandies(self,candyType):
        
        if not candyType:
            return 0 
        
        candyType.sort()
        
        
        Allowed_Number  = len(candyType) // 2  
        
        uniqueCount = 1 
        for i in range(1,len(candyType)):
            if candyType[i] != candyType[i-1]:
                uniqueCount+=1 
            
        return min(uniqueCount,Allowed_Number)
                
            
        
        
        






# Create an instance of the Solution class
sol = Solution()

# Example 1
candyType = [1,1,2,2,3,3]

Max_Candies = sol.distributeCandies(candyType)

print("Maximum Candy Type is :",Max_Candies)
