class Solution {
public:
    int dist_from_0(int x, int y) {
        return sqrt(x * x + y * y);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // we need to return the kth closest point to the origin, so let's keep a
        // max heap of size and then we will just be able to push on from that
        // we should store distance and have the pair
        priority_queue<int, pair<int, int>> pq;
        for (const auto& [x, y] : points) {
            if (pq.size() < k) {
                pq.push({dist_from_0(x, y), {x, y}});
            } else if (dist_from_0(x, y) < pq.top().first) {
                pq.pop();
                pq.push({dist_from_0(x, y), {x, y}});
            }
        }
        vector<vector<int>> result;
        return {pq.top()};
    }
};

