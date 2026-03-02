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

int main() {
    Solution sol;
    
    // Example 1
    vector<int> candyType = {1,1,2,2,3,3};
    
    cout << "Maximum Candy Type is : " << sol.distributeCandies(candyType);
    
    return 0;
}
