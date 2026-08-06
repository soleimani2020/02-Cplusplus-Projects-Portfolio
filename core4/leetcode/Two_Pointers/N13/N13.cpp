class Solution {
public:
    string reverseStr(string s, int k) {
        
        
        int n = s.size();
        
        for(int i=0 ; i < n ; i+=2*k){
            
            int end = i + k ;  // This is the LAST index plus one, i.e after the part we want to reverse. (Exclusive)
            
            if(end > n){
                end = n;
            }
            
            // in C++: reverse[start, end)
            reverse(s.begin()+i, s.begin()+end);
            
        }
        
        return s;
        
    }
};
