#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution{
public:
    
    int distributeCandies(vector<int>& candyType){
        
        if(candyType.empty())
            return 0;
            
        int Allowed_Number = candyType.size() / 2 ;
        
        
        sort(candyType.begin(), candyType.end());
        
        
        int uniqueCount=1;
        
        for(int i=1; i < candyType.size(); i++){
            
            if( candyType[i] != candyType[i-1] && uniqueCount < Allowed_Number ){
                uniqueCount++;
            }
        }
        
        return uniqueCount;
    }
};


class Solution {
public:
    int distributeCandies(vector<int>& num) {
        
        int n = num.size();
        vector<int> arr(n,1);
        
        // Scan from left to right 
        for(int i=1; i < n; i++){
            if(num[i] > num[i-1]){
                arr[i]=arr[i-1]+1;
            }
        }
        
        
        // Scan from right to left 
        for(int i=n-2; i>=0;i--){
            if(num[i] > num[i+1]){
                arr[i] = max(arr[i],arr[i+1]+1);
            }
        }
        
        int sum=0;
        for(int num : arr){
            sum+=num;
        }
        
        return sum;
        
    }
};




int main() {
    Solution sol;
    
    // Example 1
    vector<int> candyType = {1,1,2,2,3,3};
    
    cout << "Maximum Candy Type is : " << sol.distributeCandies(candyType);
    
    return 0;
}
