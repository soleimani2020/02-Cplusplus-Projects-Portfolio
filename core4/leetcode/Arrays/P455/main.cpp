#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        
        int i=0; // children's greed
        int j=0; // cookie sizes
        
        while(i<g.size() && j<s.size()){
            
            if(g[i]<=s[j]){// child satisfied
                i++;
                j++;
            }else if(g[i]>s[j]){
                j++;
            }
        }
        
        return i;
        
        
    }
};



int main() {
    vector<int> g = {1,2,3}; 
    vector<int> s = {1,1}; 

    Solution sol;
    cout << "Number of content children:" << sol.findContentChildren(g,s) << endl;
    return 0;
}


