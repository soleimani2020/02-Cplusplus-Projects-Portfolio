class Solution {
public:
    string reversePrefix(string word, char ch) {
        
        int n = word.size();
        string ans = "";
        
        int i =0;
        
        // Find the position of ch 
        while(i<n && word[i] != ch){
            i++;
        }
        
        
        // If ch is not found : reaching the end of the string without finding ch.
        if(i == n){
            return word;
        }
        
        int left  = 0;
        int right = i;
        
        while(left < right){
            swap(word[left],word[right]);
            left++;
            right--;
        }
        


        
        return word;
        
    }
};
