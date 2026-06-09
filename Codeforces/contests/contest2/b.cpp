#include <bits/stdc++.h>
using namespace std;

void helper(long long int n, vector<long long int>& output) {
    // idea is that a = n (mod 12) since b = n- a and b = 0 (mod 12)
    int a = n % 12;
    if (a == 10) a = 22; // as a needs to be a palindrom and equal to n (mod 12) 
    // we just have to find an a that is congruent to n mod 12
    // we have found our a
    // since b has to b has to be non-negative n >= a
    if (n < a) {
        output[0] = -1;
        output[1] = -1;
    } else {
        output[0] = a;
        output[1] = n - a; // since b = n - a
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        long long int num;
        cin >> num;
        vector<long long int> output(2);
        helper(num, output);
        if (output[0] == -1) {
            cout << -1;
        } else {
            cout << output[0] << " " << output[1];
        }
        cout << "\n";
    }
    return 0;
}