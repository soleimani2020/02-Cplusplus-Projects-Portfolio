#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        vector<string> result;
        int i=0;
        
        while(i<nums.size()){
            int start=nums[i];
            while( i+1<nums.size() && nums[i+1]==nums[i]+1 ){
                i++;
            }
            int end = nums[i];
            
            if (start==end){
                // single number
                result.push_back(to_string(start));
                    
            }else{
                // range
                result.push_back(to_string(start) + "->" + to_string(end));
            }
            
            i++;



        }
        
        return result;

        
        
    }
};


        



int main() {
    vector<int> nums = {0,2,3,4,6,8,9};

    Solution object;
    vector<string> R = object.summaryRanges(nums);

    cout << "Summary Ranges: ";
    for (auto &s : R) {
        cout << s << "|";
    }
    cout << endl;

    return 0;
}
