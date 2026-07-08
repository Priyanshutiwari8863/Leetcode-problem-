class Solution {
private:
    const int MOD = 1e9 + 7;

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.length();
        vector<int> digits;
        vector<int> orig_idx;
        
        for (int i = 0; i < m; i++) {
            if (s[i] != '0') {
                digits.push_back(s[i] - '0');
                orig_idx.push_back(i);
            }
        }
        
        int n = digits.size();
        if (n == 0) {
            return vector<int>(queries.size(), 0);
        }
        
        vector<long long> prefSum(n + 1, 0);
        vector<long long> prefNum(n + 1, 0);
        vector<long long> pow10(n + 1, 1);
        
        for (int i = 0; i < n; i++) {
            prefSum[i + 1] = prefSum[i] + digits[i];
            prefNum[i + 1] = (prefNum[i] * 10 + digits[i]) % MOD;
            pow10[i + 1] = (pow10[i] * 10) % MOD;
        }
        
        vector<int> answer;
        answer.reserve(queries.size());
        
        for (const auto& q : queries) {
            int L = q[0], R = q[1];
            
            auto it1 = lower_bound(orig_idx.begin(), orig_idx.end(), L);
            auto it2 = upper_bound(orig_idx.begin(), orig_idx.end(), R);
            
            if (it1 == it2) {
                answer.push_back(0);
                continue;
            }
            
            int idx1 = distance(orig_idx.begin(), it1);
            int idx2 = distance(orig_idx.begin(), it2) - 1;
            
            long long current_sum = prefSum[idx2 + 1] - prefSum[idx1];
            int len = idx2 - idx1 + 1;
            long long x = (prefNum[idx2 + 1] - (prefNum[idx1] * pow10[len]) % MOD + MOD) % MOD;
            
            long long ans = (x * current_sum) % MOD;
            answer.push_back(ans);
        }
        
        return answer;
    }
};