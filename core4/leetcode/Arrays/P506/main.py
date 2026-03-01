class Solution:
    def findRelativeRanks(self, score):
       
        if not score :
            return []
           
        mp = { }  # Score ---> Rank
        sortedScore = sorted(score, reverse=True)
       
        for i in range(len(sortedScore)):
            if   i==0:
                mp[sortedScore[i]]="Gold Medal"
            elif i==1:
                mp[sortedScore[i]]="Silver Medal"
            elif i==2:
                mp[sortedScore[i]]="Bronze Medal"
            else:
                mp[sortedScore[i]]=str(i + 1)
       
       
       
        result = [mp[s] for s in score]
       
           
        return result
           
       
       
       
       
       
   
       

           
       




score = [5,4,3,2,1]

# Assuming you have a Solution class with the intersection method
sol = Solution()
res = sol.findRelativeRanks(score)

print("Output:", end=" ")
for x in res:
    print(x, end=" ")
print()


