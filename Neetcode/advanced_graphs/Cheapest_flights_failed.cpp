class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // we will use dijkstra's with a slight modification that we drop
        // the route if we go above k flights
        vector<int> cost_arr(n, INT_MAX);
        // src -> (dst, cost)
        unordered_map<int, vector<pair<int, int>>> adj;
        for (const auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        // we will explore the cheapest to our frontier
        // we should include which node we are and how much cost and how many trips 
        // we are at
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
        // we start at src where it is free and 0 trips yet
        pq.push({0, src, 0});
        while (!pq.empty()) {
            auto [cost, node, trips] = pq.top();
            pq.pop();
            if (cost > cost_arr[node]) continue; // stale
            if (trips == k) continue; // we can't take any more trips for this path
            for (const auto& [d, c] : adj[node]) {
                // let's check out this
                int new_cost = c + cost;
                if (new_cost < cost_arr[d]) {
                    cost_arr[d] = new_cost;
                    // add to queue as this is a new frontier
                    pq.push({new_cost, d, trips + 1});
                }
            }
        }
        if (cost_arr[dst] == INT_MAX) return -1;
        return cost_arr[dst];
    }
};

