#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution_Hash {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        if (nums.empty()) return false;
        
        unordered_map<int,int> mp; // number---> freq
        
        
        for(int i=0; i< nums.size(); i++){
            
            if (mp.count(nums[i])){
                return true; // duplicate found 
            }else{
                mp[nums[i]]=1;
            }
        }
        
        return false;
  
    }
};








class Solution_SORT {
public:


    void swap(int& x , int& y){
        int temp = x;
        x = y;
        y = temp;
    }
    
    
    void BubbleSort(vector<int>& nums){
        
    int n = nums.size();
    
    for(int i = 0; i < n - 1; i++)
        for(int j = 0; j < n - i - 1; j++){
            if (nums[j] > nums[j + 1]){
                swap(nums[j], nums[j + 1]);
            }
        }
    }
    
    
    bool containsDuplicate(vector<int>& nums) {
        if (nums.empty()) return false;
    
        BubbleSort(nums);
    
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1])
                return true;
        }
    
        return false;
    }
    
    
};




int main(){
    
    vector<int> nums = {1,1,1,3,3,4,3,2,4,2};
    
    Solution_Hash object;
    
    cout << "### Finding Duplicate Using Hash Method ###" <<endl;
    
    if(object.containsDuplicate(nums)){
        cout << "There is duplicate !"<< endl;
    }else{
        cout << "There is NO duplicate !"<< endl;
    }
    

    
}
