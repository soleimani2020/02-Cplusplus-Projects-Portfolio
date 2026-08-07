class Solution {
public:
    string decodeString(string s) {
        stack<int> numsbers;
        stack<string> letters;
        
        int num =0;
        string ans = "";
        
        for(char c : s) {
            if(isdigit(c)){
                num = num*10 + c - '0';
            }else if(c != '[' && c != ']') {
                ans += c;
            }
            
            if(c=='['){
                letters.push(ans);
                numsbers.push(num);
                ans = "";      // start a new substring
                num = 0;
            }
            
            if(c==']'){
                int repeat = numsbers.top();
                numsbers.pop();
                string repeat_st = letters.top();
                letters.pop();
                string str_new = "";
                for(int i=0; i < repeat; i++){
                    str_new += ans;
                }
                
                str_new = repeat_st + str_new;
                ans = str_new;
                
                
            }

        }
        
        return ans;

        
    }
};
