class Solution:
    def findWords(self,words):
        
        if not words: 
            return []
        
        mp={}
        
        for c in "qwertyuiop": mp[c]=1 
        for c in "asdfghjkl" : mp[c]=2
        for c in "zxcvbnm"   : mp[c]=3 
        
        
        result=[]
        
        for i in range(0,len(words)):
            skip = False
            word = words[i]
            ref_c = word[0].lower()
            row = mp[ref_c]
            
            for j in range(1,len(word)):
                if( row != mp[word[j].lower()]):
                    skip=True
                    break 
            
            if(skip):
                continue 
            
            result.append(word)
            
        return result
                    
        
            
        










if __name__ == "__main__":
    sol = Solution()
    
    words = ["Hello", "Alaska", "Dad", "Peace"]
    result = sol.findWords(words)
    
    for word in result:
        print(word, end=" ")
