class Solution {
private:
    int max_depth = 0;
    const int MOD = 1e9 + 7;

    void dfs(int node, int parent, int depth, const vector<vector<int>>& adj) {
        max_depth = max(max_depth, depth);
        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                dfs(neighbor, node, depth + 1, adj);
            }
        }
    }

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
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        max_depth = 0;
        dfs(1, 0, 0, adj);
        
        if (max_depth == 0) return 1;
        
        return power(2, max_depth - 1);
    }
};