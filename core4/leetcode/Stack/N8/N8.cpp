class Solution {
public:
    string decodeString(string s) {
        
        // 12[a]
        int n = s.size();
        int num =0 ;
        string inner_str = "";
        
        stack<string> letters;
        stack<int> numbers;
        
        for(char c: s){
            if(isdigit(c)){
                num = num *10 + c - '0';
            }else if(c != '[' && c != ']'){
                inner_str += c;
            }
            
            if(c =='['){
                numbers.push(num);
                letters.push(inner_str);
                num = 0;
                inner_str ="";
            }
            
            if(c == ']'){
                int repeat = numbers.top();
                numbers.pop();
                string outer_str = letters.top();
                letters.pop();
                string str_new = "";
                for(int i=0; i<repeat; i++){
                    str_new += inner_str;
                }
                
                str_new = outer_str + str_new;
                inner_str = str_new;
                
                
            }
            
            
            
            
            
            
        }
        
        return inner_str;
        
        
        
        
    }
};
