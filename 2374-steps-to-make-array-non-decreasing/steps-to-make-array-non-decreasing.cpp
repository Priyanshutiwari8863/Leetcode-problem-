class Solution {
public:
    int totalSteps(vector<int>& nums) {
        stack<pair<int, int>> st;
        int maxSteps = 0;

        for (int num : nums) {
            int curSteps = 0;

            while (!st.empty() && st.top().first <= num) {
                curSteps = max(curSteps, st.top().second);
                st.pop();
            }

            int steps = st.empty() ? 0 : curSteps + 1;
            maxSteps = max(maxSteps, steps);

            st.push({num, steps});
        }

        return maxSteps;
    }
};