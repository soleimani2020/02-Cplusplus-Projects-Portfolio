#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())  return -1;
       
        int replace = 1;
       
        for(int i =1 ; i< nums.size(); i++){
            if (nums[i] != nums[i-1]){
                nums[replace] = nums[i];
                replace++;
            }
 
        }
       
        return replace;
       
    }
};

int main(){
   
    Solution object;
   
    vector<int> nums = {5,6,7,7,7,8};
   
   
    // vector can not be printed with cout
    int  k = object.removeDuplicates(nums) ;
   
    cout << "Number of unique elements:" << k << endl;
   
    cout << "New Nums"<< endl;
   
    for(int i=0; i<k;i++){
        cout << nums[i];
    }
   
   
   
   
   
   
   
   
}
