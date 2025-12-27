class Solution {
public:
    int totalNQueens(int n) {
        vector<int> col(n, 0), diag1(2*n, 0), diag2(2*n, 0);
        int ans = 0;
        dfs(0, n, col, diag1, diag2, ans);
        return ans;
    }
    
    void dfs(int r, int n, vector<int>& col, vector<int>& d1, vector<int>& d2, int& ans) {
        if (r == n) {
            ans++;
            return;
        }
        for (int c = 0; c < n; c++) {
            if (col[c] || d1[r + c] || d2[r - c + n]) continue;
            col[c] = d1[r + c] = d2[r - c + n] = 1;
            dfs(r + 1, n, col, d1, d2, ans);
            col[c] = d1[r + c] = d2[r - c + n] = 0;
        }
    }
};
