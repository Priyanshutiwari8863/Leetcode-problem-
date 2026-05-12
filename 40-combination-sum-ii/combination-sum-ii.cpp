class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            // Optimization: if the number is greater than the remaining target, no point in continuing
            if (candidates[i] > target) break;

            // Skip duplicates at the same level of recursion
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            current.push_back(candidates[i]);
            // i + 1 because each number can only be used once
            backtrack(candidates, target - candidates[i], i + 1, current, result);
            current.pop_back(); // Backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> current;
        backtrack(candidates, target, 0, current, result);
        return result;
    }
};