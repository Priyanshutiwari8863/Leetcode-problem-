class Solution {
public:
    int mod = 1337;

    int power(int a, int k) {
        int res = 1;
        a %= mod;
        while (k > 0) {
            if (k & 1)
                res = (res * a) % mod;
            a = (a * a) % mod;
            k >>= 1;
        }
        return res;
    }

    int superPow(int a, vector<int>& b) {
        int res = 1;
        for (int digit : b) {
            res = power(res, 10) * power(a, digit) % mod;
        }
        return res;
    }
};