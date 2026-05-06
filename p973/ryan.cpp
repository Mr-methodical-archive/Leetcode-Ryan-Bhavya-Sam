class Solution {
public:
    double distance(int x, int y) {
        return x * x + y * y;
    }
    // the comparator function asks if a should be below b
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto compare = [this](const vector<int> first, const vector<int> second) {
            return distance(first[0], first[1]) > distance(second[0], second[1]);
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> pq(compare);
        for (vector<int> point : points) {
            pq.push(point);
        }
        vector<vector<int>> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(pq.top());
            pq.pop();
        }
        return result;
    }
};
