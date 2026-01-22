/******************************************************************************

                              88.Merge Sorted Arrays

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i = m-1;   // last valid element of nums1
        int j = n-1;   // last valid element of nums2
        int k = n+m-1; // last index of nums1
        
        while(j>=0){
            
            if (i >= 0 && nums1[i]>nums2[j]){
                nums1[k]= nums1[i];
                i--;

            }else{
                nums1[k]= nums2[j];
                j--;
            }
            
            k--;

        }
        

    }
};


int main()
{   
    
    Solution object;
    
    vector<int> nums1={1,2,3,0,0,0};
    int m=3;
    
    vector<int> nums2={2,5,6};
    int n=3;
    
    object.merge(nums1,m,nums2,n);
    
    
    cout << "Merged Array:" << endl;
    for(int i=0; i<nums1.size();i++){
        cout << nums1[i];
    }
    


    return 0;
}



