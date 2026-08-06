class Solution {
public:
    string reverseStr(string s, int k) {
        
        
        int n = s.size();
        
        for(int i=0 ; i < n ; i+=2*k){
            
            int end = i + k ;  // This is the LAST index plus one (Exclusive)
            
            if(end > n){
                end = n;
            }
            
            
            reverse(s.begin()+i, s.begin()+end);
            
        }
        
        return s;
        
    }
};
