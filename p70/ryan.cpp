class Solution {
public:
    int climbStairs(int n) {
        // There are only 2 ways to get to next level: add two stairs to all paths that are 2 stairs below
        // add 1 path to all stairs 1 step below
        // We will build up from the ground
        if (n == 0 || n == 1) return 1;
        int down_2 = 1;
        int down_1 = 1;
        for (int i = 2; i <= n; ++i) {
            int new_path = down_1 + down_2;
            down_2 = down_1;
            down_1 = new_path;
        }
        return down_1;
    }
};
