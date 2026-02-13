#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        
        vector<string> output;
        unordered_map<char,int> rows;
        
        
        // First row 
        for(char c : "qwertyuiop") rows[c] =1;
        // Second row
        for (char c : "asdfghjkl") rows[c] =2;
        // Third row
        for (char c : "zxcvbnm")   rows[c] =3;
        
        
        vector<string> ans;
        
        // Loop through each word
        for(int i=0; i < words.size(); i++){
            
            // first character of each word : Determine the reference row for the word
            int r = rows[tolower(words[i][0])];
            // A flag that will tell us if we need to skip this word because it contains letters from multiple rows.
            // skip should be reset every time and therefore is defined inside the loop 
            bool skip = false;
    
                        
            for (int j = 1; j < words[i].size(); j++) { // start from 1
                char c = words[i][j];
                // we need to compare keyboard raws here and therefore two int are compared !
                if (rows[tolower(c)] != r) {
                    skip = true;
                    break;
                }
            }

            
            if (skip) continue;  // skips the rest of the outer loop body for this word
            ans.push_back(words[i]);

            /*
            if(!skip)
                ans.push_back(words[i]);
            */


        }
        
        return ans;
  
    }
};


int main() {
    Solution sol;
    
    vector<string> words = {"Hello", "Alaska", "Dad", "Peace"};
    vector<string> result = sol.findWords(words);
    
    for (const string& word : result) {
        cout << word << " ";
    }
    
    return 0;
}





