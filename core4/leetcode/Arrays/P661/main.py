class Solution:
    def imageSmoother(self, img):
        rows = len(img)
        cols = len(img[0])
        
        smoothed = [[0 for _ in range(cols)] for _ in range(rows)]
        
        for i in range(rows):
            for j in range(cols):
                cell = img[i][j]
                count = 1
                total = img[i][j]
                
                # (i-1, j-1)
                if i-1 >= 0 and j-1 >= 0:
                    count += 1
                    total += img[i-1][j-1]
                
                # (i-1, j)
                if i-1 >= 0:
                    count += 1
                    total += img[i-1][j]
                
                # (i-1, j+1)
                if i-1 >= 0 and j+1 < cols:
                    count += 1
                    total += img[i-1][j+1]
                
                # (i, j-1)
                if j-1 >= 0:
                    count += 1
                    total += img[i][j-1]
                
                # (i, j+1)
                if j+1 < cols:
                    count += 1
                    total += img[i][j+1]
                
                # (i+1, j-1)
                if i+1 < rows and j-1 >= 0:
                    count += 1
                    total += img[i+1][j-1]
                
                # (i+1, j)
                if i+1 < rows:
                    count += 1
                    total += img[i+1][j]
                
                # (i+1, j+1)
                if i+1 < rows and j+1 < cols:
                    count += 1
                    total += img[i+1][j+1]
                
                ave = total // count # integer division
                smoothed[i][j] = ave   
        
        return smoothed


# Example usage
image = [[1, 1, 1],
         [1, 0, 1],
         [1, 1, 1]]

obj = Solution()
res = obj.imageSmoother(image)

for row in res:
    print(row)