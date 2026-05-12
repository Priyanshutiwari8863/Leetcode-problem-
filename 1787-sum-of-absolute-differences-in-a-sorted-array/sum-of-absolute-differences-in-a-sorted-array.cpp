class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);

        long long totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        long long prefixSum = 0;

        for (int i = 0; i < n; i++) {
            long long left = (long long)nums[i] * i - prefixSum;
            long long right = (totalSum - prefixSum - nums[i]) 
                            - (long long)nums[i] * (n - i - 1);

            ans[i] = left + right;
            prefixSum += nums[i];
        }

        return ans;
    }
};