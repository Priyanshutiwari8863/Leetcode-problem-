class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }
        
        if (total_sum < abs(target) || (target + total_sum) % 2 != 0) {
            return 0;
        }
        
        int s1 = (target + total_sum) / 2;
        vector<int> dp(s1 + 1, 0);
        dp[0] = 1; 
        
        for (int num : nums) {
            for (int j = s1; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }
        
        return dp[s1];
    }
};