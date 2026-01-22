import numpy as np 

class Solution:
    def matrixReshape(self, mat, r , c):
        
        m , n = len(mat) , len(mat[0])
        
        if m*n != r*c:
            return mat 
            
        flat=[]
        for i in range(m):
            for j in range(n):
                flat.append(mat[i][j])
                
        # flat = [mat[i][j] for i in range(m) for j in range(n)]        
                
        
        # newMat = [[0]*c for _ in range(r)]        
        newMat=np.zeros((r,c), dtype=int)
        k=0
        for x in range(r):
            for y in range(c):
                newMat[x][y]=flat[k]
                k+=1
                
        return newMat
                






# Create an instance of the Solution class
sol = Solution()

# Example 1
mat = [[1, 2, 3], [4, 5, 6]]
r, c = 3, 2

# Call the matrixReshape method
reshaped = sol.matrixReshape(mat, r, c)

# Print the reshaped matrix
for row in reshaped:
    print(" ".join(map(str, row)))
