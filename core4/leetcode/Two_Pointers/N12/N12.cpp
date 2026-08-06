class Solution {
public:
    int trap(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n==0) return 0;
        
        vector<int> leftmax(n,0);
        vector<int> rightmax(n,0);
        
        leftmax[0] = nums[0];
        rightmax[n-1] = nums[n-1];
        
        for(int i=1; i < n ; i++){
            leftmax[i] = max(leftmax[i-1],nums[i]);
            
        }
        
        for(int i=n-2; i>=0; i--){
            rightmax[i]=max(rightmax[i+1],nums[i]);
        }
        
        
        int max_water =0;
        for(int i =0 ; i < n; i++){
            max_water+=min(leftmax[i],rightmax[i]) - nums[i];
        }
        
        return max_water;
        
        
        
    }
};
