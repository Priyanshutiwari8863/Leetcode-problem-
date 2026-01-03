class Solution {
public:
    int numOfWays(int n) {
        
        long long mod = 1e9 + 7;

        long long abc = 6;  // pattern ABC ke liye 
        long long aba = 6;  // pattern ABA  ke liye 

        for (int i = 2; i <= n; i++) {
            long long new_abc = (2 * abc + 2 * aba) % mod;
            long long new_aba = (2 * abc + 3 * aba) % mod;

            abc = new_abc;
            aba = new_aba;
        }

        return (abc + aba) % mod;
    }
};
