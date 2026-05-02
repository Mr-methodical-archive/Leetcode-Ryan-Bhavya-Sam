class Solution {
public:
    // what could be going wrong: 
    // maybe instead, we do something like a recursive approach.
    double myPow(double x, int n) {
        long exp = abs((long)n);
        double result = fastPow(x, exp);
        return n > 0 ? result : 1.0 / result;
    }  
    double fastPow(double x, long n) {
        if (n == 0) {
            return 1.0;
        }
        double retval = fastPow(x, n / 2);
        if (n % 2 == 1) {
            return x * retval * retval;
        } else {
            return retval * retval;
        }
    }
};
