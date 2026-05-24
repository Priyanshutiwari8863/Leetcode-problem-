class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        stack<int> st;
        int maxSteps = 0;

        for (int i = 0; i < n; i++) {
            int curSteps = 0;

            while (!st.empty() && nums[st.top()] <= nums[i]) {
                curSteps = max(curSteps, dp[st.top()]);
                st.pop();
            }

            if (!st.empty()) {
                dp[i] = curSteps + 1;
            } else {
                dp[i] = 0;
            }

            maxSteps = max(maxSteps, dp[i]);
            st.push(i);
        }

        return maxSteps;
    }
};