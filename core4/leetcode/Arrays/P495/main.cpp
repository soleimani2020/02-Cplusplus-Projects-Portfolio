#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        
        if(timeSeries.empty()) return 0;
        
        int prev_end = timeSeries[0]+duration-1;
        int total = duration;
        
        // next step: loop through the remaining attacks
        for(int i=1; i < timeSeries.size(); i++){
            if (timeSeries[i]>prev_end){
                // No overlap : add full duration
                total+=duration;
            }else{// overlap : add "calculated" duration
                total += (timeSeries[i] + duration - 1 - prev_end);
            }
            prev_end = timeSeries[i] + duration - 1;
        }
        return total;
    }
};


int main() {
    vector<int> timeSeries = {1,2};
    
    int duration = 2;

    Solution sol;
    
    cout << "The total number of seconds Ashe is poisoned is : " << sol.findPoisonedDuration(timeSeries,duration) << endl;

    return 0;
}
