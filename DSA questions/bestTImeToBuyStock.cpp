class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low = 0, current = 0, max_profit = 0;
        while(current < prices.size()){
            if(prices[current] > prices[low] && max_profit < (prices[current] - prices[low]))
               max_profit = prices[current] - prices[low];
            else if(prices[current] <= prices[low]) low = current++;
            else current++;
        }
        return max_profit;
    }
};