#include <bits/stdc++.h>
using namespace std;

long long helper(vector<int>& arr, int drain) {
    // the second argument is the one we are not doing
    int n = arr.size();
    vector<int> cw_limit(n, 0);
    vector<int> ccw_limit(n, 0);

    int max_wall = 0;
    for (int step = 1; step < n; ++step) {
        int prev_vessel = (drain + step - 1) % n;
        int wall = arr[prev_vessel];
        max_wall = max(wall, max_wall);
        int curr_vessel = (drain + step) % n;
        cw_limit[curr_vessel] = max_wall;
    }

    max_wall = 0;
    for (int step = 1; step < n; ++step) {
        int prev_vessel = (drain - step + 1 + n) % n;
        int wall = arr[(prev_vessel - 1 + n) % n];
        
        max_wall = max(max_wall, wall);
        
        int curr_vessel = (drain - step + n) % n;
        ccw_limit[curr_vessel] = max_wall;
    }

    long long total_water = 0;
    for (int i = 0; i < n; ++i) {
        if (i != drain) { // as this would just be zero
            total_water += min(cw_limit[i], ccw_limit[i]);
        }
    }
    return total_water;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int num;
        cin >> num;
        vector<int> arr;
        for (int i = 0; i < num; ++i) {
            int input;
            cin >> input;
            arr.push_back(input);
        }
        for (int i = 0; i < num; ++i) {
            if (i != 0) cout << " "; 
            cout << helper(arr, i);
        }
        cout << "\n";
    }
    return 0;
}