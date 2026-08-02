class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        n = len(word1)
        m = len(word2)
        
        i = 0 
        ans = ""
        
        while i < n and i < m :
            ans += word1[i]
            ans += word2[i]
            i+=1 
            
        while i < n:
            ans += word1[i]
            i+=1 
            
        while i < m:
            ans += word2[i]
            i+=1 
            
        return ans 
            
        
