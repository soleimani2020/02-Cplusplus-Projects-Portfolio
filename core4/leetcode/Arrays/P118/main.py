class Solution:
    def generate(self,numRows):
        
        result = []
        
        first_row=[1];
        result.append(first_row)
        
        if(numRows==1):
            return result
            
        for i in range(1,numRows):
            prev_row = result[i-1]
            
            row=[1]
            for j in range(0,len(prev_row)-1):
                row.append(prev_row[j]+prev_row[j+1])
            row.append(1)
            result.append(row)
        
        return result
                
    
    
    
    
    
    
    
    
    
    
    
        
# ---- Main ----
numRows = 5

solution = Solution()
result = solution.generate(numRows)
print(result)


        

        
