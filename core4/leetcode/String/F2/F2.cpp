class Solution {
public:
    string reversePrefix(string s, int k) {

        int n = s.size();
        int i = 0;

        int end = i + k;

        if (end > n) {
            end = n;
        }

        reverse(s.begin() + i, s.begin() + end);

        return s;
    }
};
