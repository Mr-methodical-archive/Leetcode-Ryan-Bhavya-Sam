class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int curr_cost = 0;
        int down_1 = 0;
        int down_2 = 0;
        for (int i = 0; i < cost.size(); ++i) {
            curr_cost = cost[i] + min(down_1, down_2);
            down_2 = down_1;
            down_1 = curr_cost;
        }
        return min(curr_cost, down_2);
    }
};
