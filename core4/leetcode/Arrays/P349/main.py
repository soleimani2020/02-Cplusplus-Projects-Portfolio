class Solution:
    def intersection(self,nums1,nums2):
        
        result=[]
        
        
        nums1.sort()
        nums2.sort()
        
        
        i=0
        j=0
        # While elemnts left in i and j 
        while(i<len(nums1) and j<len(nums2)):
            if nums1[i] < nums2[j]:
                i+=1 
            
            elif nums1[i] > nums2[j]:
                j+=1 
            
            else :
                # Equal 
                if len(result)==0 or result[-1] != nums1[i]:
                    result.append(nums1[i])
                i+=1 
                j+=1 
            
        return result
        
            
        




nums1 = [1, 2, 2, 1, 3]
nums2 = [2, 2, 3]

# Assuming you have a Solution class with the intersection method
sol = Solution()
res = sol.intersection(nums1, nums2)

print("Intersection:", end=" ")
for x in res:
    print(x, end=" ")
print()
