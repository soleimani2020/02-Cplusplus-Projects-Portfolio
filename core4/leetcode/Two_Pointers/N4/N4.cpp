class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        string ans = "";
        int i = 0;
        
        while(i < n && i < m){
            ans += word1[i] ;
            ans += word2[i];
            i++;
        }
        
        while(i < n){
            ans += word1[i];
            i++;
        }
        
        while(i < m){
            ans += word2[i];
            i++;
        }
        
        return ans;
    }
};
