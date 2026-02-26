class Solution_Recursion:
    def floodFill(self, image , sr, sc, newColor):
        
        rows = len(image)
        cols = len(image[0])
        
        initial_color = image[sr][sc] 
        
        # base case :
        if initial_color == newColor:
            return image
            
        
        image[sr][sc]  =  newColor
            
        # check nrighbors recursively
        
        if sr>0 and image[sr-1][sc]==initial_color:
           self.floodFill(image , sr-1, sc, newColor) 

        if sr<rows-1 and image[sr+1][sc]==initial_color:
           self.floodFill(image , sr+1, sc, newColor)               

        if sc>0 and image[sr][sc-1]==initial_color:
           self.floodFill(image , sr, sc-1, newColor) 

        if sc <cols-1 and image[sr][sc+1]==initial_color:
           self.floodFill(image , sr, sc+1, newColor)  
           
           
        return image 




if __name__ == "__main__":
    image = [
        [1, 1, 1],
        [1, 1, 0],
        [1, 0, 1]
    ]

    sr, sc = 1, 1
    newColor = 2

    sol = Solution_Recursion()
    res = sol.floodFill(image, sr, sc, newColor)

    print("Flood Filled Image:")
    for row in res:
        print(" ".join(str(val) for val in row))
