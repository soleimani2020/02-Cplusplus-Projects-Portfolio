class Solution {
    
private:

    bool IsPallindrum(string s, int left , int right){
        
        while(left < right){
            if(s[left] != s[right]){
                return false;
            }else{
                left++;
                right--;
            }
        }
        
        return true;
    }


    
public:
    bool validPalindrome(string s) {
        
        int n = s.size();
        int left = 0 ;
        int right = n-1;
        while(left<right){
            
            if(s[left]==s[right]){
                left++;
                right--;
            }else{

                bool a = IsPallindrum(s,left+1,right);
                bool b = IsPallindrum(s,left,right-1);
                return  a || b;
            }
        }
        
        return true;
        
    }
};

















