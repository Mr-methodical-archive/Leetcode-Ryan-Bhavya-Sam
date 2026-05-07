class Solution {
public:
    int arr[31];
    int helper(int n) { // arrays are passed in as pointers
        if (n <= 1) return n;
        if (arr[n] != 0) return arr[n];
        arr[n] = fib(n - 1) + fib(n - 2);
        return arr[n];
    }
    int fib(int n) {
        return helper(n);
    }
};
