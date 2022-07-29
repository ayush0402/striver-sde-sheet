class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.00000;
        bool neg = false;
        if (n < 0)neg = true;
        n = abs(n);
        while (n > 0) {
            if (n % 2 == 1)res *= x;
            x *= x;
            n /= 2;
        }
        if (neg) {
            res = 1.00000 / res;
        }
        return res;
    }
};
