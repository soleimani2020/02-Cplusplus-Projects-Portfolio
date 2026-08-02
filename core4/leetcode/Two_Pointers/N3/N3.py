class Solution:
    def IsPallindrom(self,s,left,right):
        while left < right:
            if s[left] == s[right]:
                left+=1
                right-=1 
            else:
                return False 
        return True 
        
    
    
    
    def validPalindrome(self, s: str) -> bool:
        n = len(s)
        left = 0 
        right = n-1;
        
        while left < right:
            if s[left] == s[right]:
                left+=1 
                right-=1
            else:
                return self.IsPallindrom(s,left+1,right) or self.IsPallindrom(s,left,right-1)
            
        return True 
                
                
