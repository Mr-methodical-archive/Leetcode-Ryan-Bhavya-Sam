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
  // k must be at least the size of the smallest gap
  int k = 0;
  for (int i = 1; i < num; ++i) {
    k = max(k, arr[i - 1] - arr[i]);
  }
  if (k == 0) {
    cout << "YES\n";
    return;
  }
  // it must be at least k basically that is the idea, and doing the min
  // jump we have to do will actually work
  for (int i = 1; i < num; ++i) {
    if (arr[i - 1] > arr[i]) {
      arr[i] += k;
    }
  }
  // now we did the smallest fix possible that we could do and just have 
  // make sure it is sorted now
  for (int i = 1; i < num; ++i) {
    if (arr[i - 1] > arr[i]) {
      cout << "NO\n";
      return;
    }
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
