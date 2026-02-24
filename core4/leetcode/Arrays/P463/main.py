class Solution:
    def islandPerimeter(self, grid):
        if not grid:
            return 0
            
        total = 0
        rows = len(grid)
        cols = len(grid[0])
        
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1:
                    perimeter = 4
                    # up
                    if i > 0 and grid[i-1][j] == 1:
                        perimeter -= 1
                    # down
                    if i < rows - 1 and grid[i+1][j] == 1:
                        perimeter -= 1
                    # left
                    if j > 0 and grid[i][j-1] == 1:
                        perimeter -= 1
                    # right
                    if j < cols - 1 and grid[i][j+1] == 1:
                        perimeter -= 1
                    
                    total += perimeter
        
        return total
                    


if __name__ == "__main__":
    grid = [
        [0, 1, 0, 0],
        [1, 1, 1, 0],
        [0, 1, 0, 0],
        [1, 1, 0, 0]
    ]

    sol = Solution()
    perimeter = sol.islandPerimeter(grid)
    print("Island Perimeter:", perimeter)
