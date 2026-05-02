class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n == -1) return 1 / x;
        int half = n / 2;
        int rem = n - half;
        double retval = 1;
        if (abs() >= 1) {
            retval = x * x;
        } else {
            for (int i = 0; i < n; ++i) {
                retval *= x;
            }
            return n > 0 ? retval : 1 / retval;
        }
        if (n > 0) {
            return  myPow(x, rem) * retval;
        } 
        return myPow(x, rem) / retval;
    }
    /*
    // what could be going wrong: 
    // maybe instead, we do something like a recursive approach.
    double myPow(double x, int n) {
        int mult = 0;
        int num = 1;
        long num1 = abs(n);
        // ex. 5 we would want to get 2 out of it 
        // ex. 9 we would would want 3
        while (2 * num <= num1) {
            num *= 2;
            mult++;
        }
        // good satisfied both
        double product = x;
        for (int i = 0; i < mult; ++i) {
            product *= product;
        }
        for (int i = 0; i < n - num; ++i) {
            product *= x;
        }
        if (n == 0) {
            return 1;
        } else if (n > 0) {
            return product;
        } 
        return 1 / product;
    }
    */
};
