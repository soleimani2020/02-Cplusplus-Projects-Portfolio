class Solution:
    def maxProfit(self,prices):
        if not prices:
            return 0;
            
        
        max_profit=0
        buy_time=prices[0]
        
        for i in range(1,len(prices)):
            if prices[i] < buy_time:
                buy_time = prices[i]
            
            pot_max_profit = prices[i] - buy_time
            if pot_max_profit > max_profit:
                max_profit = pot_max_profit
        
        return max_profit
        

if __name__ == "__main__":
    prices = [7, 1, 5, 3, 6, 4]
    
    solution = Solution()
    result = solution.maxProfit(prices)
    
    print(f"Maximum profit: {result}")

