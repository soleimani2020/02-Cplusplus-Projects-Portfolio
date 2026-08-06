class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        
        n = len(s)
        s = list(s)  # Convert to list for mutability
        for i in range(0,n,2*k):
            end = i + k 
            if end > n :
                end = n 
            
            s[i:end] = reversed(s[i:end])
            
        
        return ''.join(s)
        
