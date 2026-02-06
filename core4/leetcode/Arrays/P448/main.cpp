class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        vector<int> result;
        vector<int> nums2;
        
        sort(nums.begin(), nums.end());
        
        // remove duplicates
        for(int num: nums){
            if (nums2.empty()  || num != nums2.back()){
                nums2.push_back(num);
            }
        }
        
        

        // Mising numbers before the first element 
        for (int x=1; x<nums2[0]; x++){
            result.push_back(x);
        }
        
        
        
        // Missing numbers in between 
        for(int i=1; i<nums2.size();i++){
            if( nums2[i] > nums2[i-1]+1 ){
                for(int x=nums2[i-1]+1 ; x <= nums2[i]-1 ; x++){
                    result.push_back(x);
                    
                }
                
            }
            
        }
        
        // Missing numbers after the last elemnt
        for(int x=nums2.back()+1 ; x <= nums.size(); x++){
            result.push_back(x);
        }
        
        
        
        
        return  result;



        
    }
};
