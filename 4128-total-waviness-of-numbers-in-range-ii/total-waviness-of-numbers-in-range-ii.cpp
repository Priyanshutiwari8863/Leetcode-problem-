
struct DPResult {
    long long count;
    long long sum_waviness;
};

class Solution {
    DPResult dp[16][2][2][11][11];
    string num_str;

    DPResult solve_dp(int idx, bool tight, bool leading_zero, int last_digit, int second_last_digit) {
        if (idx == num_str.length()) {
            return {1, 0};
        }

        if (dp[idx][tight][leading_zero][last_digit][second_last_digit].count != -1) {
            return dp[idx][tight][leading_zero][last_digit][second_last_digit];
        }

        int limit = tight ? (num_str[idx] - '0') : 9;
        long long total_count = 0;
        long long total_waviness = 0;

        for (int digit = 0; digit <= limit; ++digit) {
            bool next_tight = tight && (digit == limit);
            bool next_leading_zero = leading_zero && (digit == 0);

            int waviness_contribution = 0;
            
            if (!leading_zero && second_last_digit != 10) {
                if (last_digit > second_last_digit && last_digit > digit) {
                    waviness_contribution = 1;
                } else if (last_digit < second_last_digit && last_digit < digit) {
                    waviness_contribution = 1;
                }
            }

            DPResult next_res = solve_dp(
                idx + 1, 
                next_tight, 
                next_leading_zero, 
                next_leading_zero ? 10 : digit, 
                next_leading_zero ? 10 : last_digit
            );

            total_count += next_res.count;
            total_waviness += next_res.sum_waviness + (waviness_contribution * next_res.count);
        }

        return dp[idx][tight][leading_zero][last_digit][second_last_digit] = {total_count, total_waviness};
    }

    long long get_total_waviness_up_to(long long X) {
        if (X < 100) return 0;
        
        num_str = to_string(X);
        memset(dp, -1, sizeof(dp));
        
        return solve_dp(0, true, true, 10, 10).sum_waviness;
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        return get_total_waviness_up_to(num2) - get_total_waviness_up_to(num1 - 1);
    }
};