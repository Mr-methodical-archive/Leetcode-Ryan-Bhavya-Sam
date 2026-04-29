#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int current_val = nums[i] + nums[j];
                if (target == current_val) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

