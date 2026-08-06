
class Solution {
public:
    string reverseWords(string s) {

        int n = s.size();
        string ans = "";

        for(int i = 0; i < n; i++) {

            // Extract individual word
            string word = "";

            while(i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }
           

            // Reverse the word using two pointers instead of reverse(word.begin(),word.end())
            int left = 0;
            int right = word.size() - 1;

            while(left < right) {
                swap(word[left], word[right]);
                left++;
                right--;
            }

            // Add reversed word to answer
            if(!word.empty()) {

                if(!ans.empty()) {
                    ans += ' ';
                }

                ans += word;
            }
        }

        return ans;
    }
};
