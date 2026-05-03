class Solution {
public:
    int coinChangeHelper(vector<int>& coins, int amount, int count) {
        if (amount < 0) return INT_MAX;
        if (amount == 0) return count;
        int smallest_count = INT_MAX;
        for (int coin : coins) {
            smallest_count = min(smallest_count, coinChangeHelper(coins, amount - coin, count + 1));
        }
        return smallest_count;
    }
    int coinChange(vector<int>& coins, int amount) {
        int val = coinChangeHelper(coins, amount, 0);
        if (val == INT_MAX) {
            return -1;
        } else {
            return val;
        }
    }
};
