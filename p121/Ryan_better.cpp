class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int current_low = prices[0];
        for (int i = 0; i < prices.size(); ++i) {
            current_low = min(current_low, prices[i]);
            max_profit = max(max_profit, prices[i] - current_low);
        }
        return max_profit;
    }
};
