class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, -1);
        int max_visited = 0;
        
        for (int i = 0; i < n; ++i) {
            max_visited = max(max_visited, solve(i, arr, d, dp));
        }
        
        return max_visited;
    }

private:
    int solve(int i, const vector<int>& arr, int d, vector<int>& dp) {
        if (dp[i] != -1) return dp[i];
        
        int n = arr.size();
        int max_steps = 1;
        
        for (int x = 1; x <= d && i + x < n; ++x) {
            if (arr[i + x] >= arr[i]) break;
            max_steps = max(max_steps, 1 + solve(i + x, arr, d, dp));
        }
        
        for (int x = 1; x <= d && i - x >= 0; ++x) {
            if (arr[i - x] >= arr[i]) break;
            max_steps = max(max_steps, 1 + solve(i - x, arr, d, dp));
        }
        
        return dp[i] = max_steps;
    }
};