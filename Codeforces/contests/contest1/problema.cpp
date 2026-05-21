#include <bits/stdc++.h>
using namespace std;

bool in(vector<int>& arr, int num) {
  for (int i = 1; i < arr.size(); ++i) {
    if (arr[i - 1] + arr[i] == num) return false;
  }
  return true;
}

void solve() {
  int num;
  cin >> num;
  // we want all the ones between 1 and 2 * num
  // let's create a set and it will be of size
  // we could do a check if an element is in our set every time
  vector<int> arr;
  for (int i = 1; i <= num * 2; ++i) {
    if (arr.size() == num) break;
    if (in(arr, i)) {
      arr.push_back(i);
    }
  }
  for (int n : arr) {
    cout << n << " ";
  }
  cout << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
