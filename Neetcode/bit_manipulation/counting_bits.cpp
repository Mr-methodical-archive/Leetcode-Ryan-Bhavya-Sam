class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;
        result.push_back(0);
        for (int i = 1; i <= n; ++i) {
            // odds are the only time you can add more
            result.push_back(i % 2 + result[i / 2]);
        }
        return result;
    }
};

