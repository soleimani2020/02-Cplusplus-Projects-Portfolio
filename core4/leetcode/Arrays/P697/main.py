class Solution:
    def findShortestSubArray(self,num):
        if not num:
            return 0
       
        mp={}  # number → [count, first_index, last_index]
       
        for index in range(len(num)):
            x = num[index]
            if x in mp:
                mp[x][0] +=1
                lastindex = index    # increment count
                mp[x][2] = lastindex # update last index
            else:
                mp[x] = [1,index,index]
               
        degree = 0  # Keeps track of the maximum frequency
        for x in mp:
            if mp[x][0] > degree:
                degree = mp[x][0]
       
        min_length = len(num)
        for x in mp:
            if mp[x][0] == degree:
                pot_min_length = mp[x][2] - mp[x][1] + 1
                if pot_min_length < min_length:
                    min_length = pot_min_length
                   
        return min_length
                   
       
       
       
       
num = [1,2,2,3,1]
sol = Solution()
print("The minimum array length is: ", sol.findShortestSubArray(num))  

