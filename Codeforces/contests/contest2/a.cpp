#include <bits/stdc++.h>
using namespace std;

bool euclid(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 2; ++i) {
        int res = arr[i] % arr[i + 1];
        if (res != arr[i + 2]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int times;
        cin >> times;
        vector<int> arr;
        for (int i = 0; i < times; ++i) {
            int num;
            cin >> num;
            arr.push_back(num);
        }
        // first sort the array:
        sort(arr.begin(), arr.end(), greater<int>());
        if (euclid(arr)) {
            cout << arr[0] << " " << arr[1] << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    return 0;
}