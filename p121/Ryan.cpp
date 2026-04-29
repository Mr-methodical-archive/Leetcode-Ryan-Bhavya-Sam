class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int small_index = 0;
        int big_index = 0;
        int max_profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
             if (prices[small_index] > prices[i]) {
                big_index = i;
                small_index = i;
             } else if (prices[big_index] < prices[i]) {
                big_index = i;
                if (prices[big_index] - prices[small_index] > max_profit) {
                    max_profit = prices[big_index] - prices[small_index];
                }
             }
        }
        return max_profit;
    }
};
