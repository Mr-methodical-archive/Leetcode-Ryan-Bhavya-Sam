class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) return 0;
        int min_index = 0;
        int max_diff = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < prices[min_index]) {
                min_index = i;
            } else {
                if (prices[i] - prices[min_index] > max_diff) {
                    max_diff = prices[i] - prices[min_index];
                }
            }
        }
        if (max_diff < 0) return 0;
        return max_diff;
    }
};