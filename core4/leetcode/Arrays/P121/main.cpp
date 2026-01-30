#include <iostream>
#include <vector>

using namespace std;

class BF_Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int max_profit = 0;
        
        for (int i = 0; i < prices.size(); i++) {
            for (int j = i + 1; j < prices.size(); j++) {
                if (prices[j] - prices[i] > max_profit) {
                    max_profit = prices[j] - prices[i];
                }
            }
        }
        
        return max_profit;
    }
};



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        // Initialize the minimum price to the first day's price
        int min_price = prices[0];
        
        // Initialize maximum profit to 0 (no transaction yet)
        int max_profit = 0;
        
        // Loop through each day's price
        for(int i = 0; i < prices.size(); i++){
            
            // Update min_price if we find a lower price
            if (prices[i] < min_price){
                min_price = prices[i];
            }
            
            // Calculate potential profit if we sell today
            int pot_max_profit = prices[i] - min_price;
            
            // Update max_profit if this potential profit is higher
            if (pot_max_profit > max_profit){
                max_profit = pot_max_profit;
            }
        }
        
        // Return the maximum profit achievable
        return max_profit;
    }
};



int main(){
    
    vector<int> prices = {7,1,5,3,6,4};
    
    BF_Solution object;
    
    cout << "Maximum profit from BF solution:" << object.maxProfit(prices) << endl;
    
    Solution object2;
    
    cout << "Maximum profit from efficient solution:" << object2.maxProfit(prices);
    
    
    
    
}
