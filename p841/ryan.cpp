class Solution {
public:
    void dfs(vector<vector<int>>& rooms, int curr_room, vector<bool>& visited) {
        if (visited[curr_room]) return;
        visited[curr_room] = true;
        for (int room : rooms[curr_room]) {
            // basically now we have the keys to all these rooms
            dfs(rooms, room, visited);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        dfs(rooms, 0, visited);
        for (int i = 0; i < rooms.size(); ++i) {
            if (!visited[i]) return false;
        }
        return true;
    }
};
