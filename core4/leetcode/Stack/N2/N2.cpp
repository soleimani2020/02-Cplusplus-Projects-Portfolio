#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;

        for(int i = 0; i < s.size(); i++) {
            
            // Push opening brackets
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            }
            else {
                // Closing bracket without opening bracket
                if(st.empty()) {
                    return false;
                }

                char top = st.top();

                // Check matching pair
                if((s[i] == ')' && top != '(') ||
                   (s[i] == ']' && top != '[') ||
                   (s[i] == '}' && top != '{')) {
                    return false;
                }

                // Remove matched opening bracket
                st.pop();
            }
        }

        // Valid only if no unmatched opening brackets remain
        return st.empty();
    }
};
