class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_water = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left < right) {
            max_water = max(max_water, (right - left) * min(height[right], height[left]));
            // we should go to the one with a bigger next one, only way the water could be more:
            if (height[left] < height[right]) {
                ++left;
            } else if (height[left] > height[right]) {
                --right;
            } else {
                ++left;
                --right;
            }
        }
        return max_water;
    }
};
