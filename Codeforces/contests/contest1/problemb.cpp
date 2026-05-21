#include <bits/stdc++.h>
using namespace std;

void solve() {
  int num;
  cin >> num;
  vector<int> arr;
  for (int i = 0; i < num; ++i) {
    int new_num;
    cin >> new_num;
    arr.push_back(new_num);
  }
  // at the start we have the full range of what k could be
  int k_lo = 1;
  int k_hi = INT_MAX;
  for (int i = 1; i < num; ++i) {
    // good if it bigger than the last:
    if (arr[i - 1] <= arr[i]) continue;
    // in the other case we need k_lo to be able to at least compensate
    int n_k_lo = arr[i - 1] - arr[i];
    int n_k_hi = (i == num.size() - 1) ? INT_MAX : arr[i + 1] - arr[i];
    // we have a new range and we have to modify current one to fit this
    if (n_k_lo > k_hi || n_k_hi < k_lo) {
      cout << "NO\n";
      return;
    }
    k_lo = max(k_lo, n_k_lo);
    k_hi = min(k_hi, n_k_hi);
    if (k_lo > k_hi) {
      cout << "NO\n";
      return;
    }
    // now we need to change the current value and just assume it takes on
    // the smallest possible value
    arr[i] = arr[i - 1];
  }
  cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
