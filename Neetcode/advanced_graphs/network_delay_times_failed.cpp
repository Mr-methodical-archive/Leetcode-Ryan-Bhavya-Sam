class Solution {
public:
    // we will return negative 1 when we are going to a node that we have already visited 
    // like if it is not in our visited list.
    int dfs(unordered_map<int, vector<pair<int, int>>>& um, int best_time, int curr_node,
            unordered_set<int>& visit, int curr_time) {
        // have we visited all of them yet?
        if (visit.empty()) {
            // we were able to visit them all
            return curr_time;
        }
        // we will go down the path of the curr_node and try all those out:
        for (const auto& p : um[curr_node]) {
            // we want to make sure the node we are exploring we haven't seen yet
            if (!visit.contains(p.first)) {
                // Not in ones we still want to visit so keep looking
                continue;
            }
            // add onto list of visited and then take off
            visit.erase(p.first);
            int retval = dfs(um, best_time, p.first, visit, curr_time + p.second);
            visit.insert(p.first);
            if (retval >= 0 && retval < best_time) {
                best_time = min(retval, best_time);
            }
        }
        if (best_time < INT_MAX) {
            return best_time; // means we found a path
        }
        return -1;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Adjacency list ui to vi and then we also have to include times
        //   we'll have ui mapped to a list of [vi, time]
        unordered_map<int, vector<pair<int, int>>> um;
        for (const auto& t : times) {
            int ui = t[0];
            int vi = t[1];
            int ti = t[2];
            pair<int, int> adj = {vi, ti};
            um[ui].push_back(adj);
        }
        // we start at k:
        // We need some way to know when we have visited them all
        // let's do unordered_set and when that is empty then we know
        unordered_set<int> visit;
        for (int i = 1; i <= n; ++i) {
            visit.insert(i);
        }
        visit.erase(k);
        return dfs(um, INT_MAX, k, visit, 0)
    }
};

