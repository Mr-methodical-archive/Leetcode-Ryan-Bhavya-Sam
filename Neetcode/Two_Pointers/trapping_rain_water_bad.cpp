class Solution {
public:
    // how do we tell how much rainwater between two points:
    int rainwater(vector<int>& height, int left, int right) {
        // this is assuming both the left and right are the barriers exactly, 
        // so the job of this function just to see how much between them
        int min_height = min(height[left], height[right]);
        int cells_between = right - left - 1;
        int area_between = cells_between * min_height;
        for (int i = left + 1; i < right; ++i) {
            if (height[i] > min_height) return 0; // they lied and not barrier
            area_between -= height[i];
        }
        return area_between;
    }
    int trap(vector<int>& height) {
        int left = 0;
        int right = 0;
        int max_trap = 0;
        // brute force is we try every possible combination of them
        // it would be an O(n^3 ) solution
        // we need to somehow know the blocks in between as well
        // somewhat like other one but then we subtract, how do we lock it in
        // maybe we could do from the start but it that might not work because there chance
        // we have to throw it away at the end
        for (int i = 0; i < height.size(); ++i) {
            for (int j = i + 1; j < height.size(); ++j) {
                max_trap += max(max_trap, rainwater(height, i, j));
            }
        }
        return max_trap;
    }
};

