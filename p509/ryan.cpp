class Solution {
public:
    int fib(int n) {
        if (n == 0 || n == 1) return n;
        // we just remember the old stuff
        int f_n_2 = 0;
        int f_n_1 = 1;
        int next;
        for (int i = 1; i < n; ++i) {
            next = f_n_2 + f_n_1;
            f_n_2 = f_n_1;
            f_n_1 = next;
        }
        return f_n_1;
    }
};
