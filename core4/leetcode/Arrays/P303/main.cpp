#include <iostream>
#include <vector>
#include <algorithm>  // Sort 

using namespace std;

class NumArray_BF {
public:

    vector<int> input;
    
    // constructor 
    NumArray_BF(vector<int>& nums) {
        input = nums;
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        for(int i = left; i <= right; i++){
            sum += input[i];
        }
        return sum;
    }
};


class NumArray {
public:

    vector<int> nums;
    vector<int> prefix;
    
    // constructor 
    NumArray(vector<int>& input) {
        nums = input;
        
        prefix.resize(nums.size()+1);
        
        prefix[0] = 0;
        for(int i=0; i< nums.size(); i++){
            prefix[i+1]=prefix[i]+nums[i];
        }
        
        
        
    }
    
    int sumRange(int left, int right) {
        
        return prefix[right+1] - prefix[left];

    }
};


int main() {
    vector<int> nums = {0,1,0,3,12};

    NumArray object(nums);
    cout << "The answer from prefix solution is :" << object.sumRange(0,4) << endl;
    
     




    return 0;
}
