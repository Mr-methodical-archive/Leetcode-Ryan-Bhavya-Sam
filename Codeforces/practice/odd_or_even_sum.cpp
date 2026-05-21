#include <bits/stdc++.h>
using namespace std;

void helper(int num) {
  int sum = 0;
  for (int i = 0; i < num; ++i) {
    int new_num;
    cin >> new_num;
    sum += new_num;
  }
  if (sum % 2 == 0) {
    cout << "EVEN";
  } else {
    cout << "ODD";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int num;
  cin >> num;
  helper(num);
}
