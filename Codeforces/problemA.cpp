#include <iostream>

using namespace std;

void solve() {
    // 1. Declare your variables for a single test case
    int numBottles, numExchange;
    
    // 2. Read them from the input stream using cin
    cin >> numBottles >> numExchange;
    
    // 3. Do your math/logic here (just like LeetCode)
    int total_drunk = numBottles;
    int empty_bottles = numBottles;
    
    while (empty_bottles >= numExchange) {
        int new_bottles = empty_bottles / numExchange;
        total_drunk += new_bottles;
        empty_bottles = (empty_bottles % numExchange) + new_bottles;
    }
    
    // 4. Print the result using cout, followed by a newline (\n)
    cout << total_drunk << "\n";
}

int main() {
    // Optimizes C++ I/O operations for speed (very important on Codeforces)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t; // Read the total number of test cases
    
    while (t--) {
        solve(); // Run your logic loop for each test case
    }
    
    return 0;
}
