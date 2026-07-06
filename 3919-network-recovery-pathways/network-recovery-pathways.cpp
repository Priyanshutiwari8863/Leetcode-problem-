#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    bool check(int n, const vector<vector<pair<int, int>>>& adj, const vector<bool>& online, long long k, int min_cost_limit) {
        if (!online[0] || !online[n - 1]) return false;

        vector<long long> min_total_cost(n, -1);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        min_total_cost[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [curr_cost, u] = pq.top();
            pq.pop();

            if (curr_cost > min_total_cost[u]) continue;
            if (u == n - 1) return curr_cost <= k;

            for (const auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (!online[v] || weight < min_cost_limit) continue;

                if (min_total_cost[v] == -1 || curr_cost + weight < min_total_cost[v]) {
                    min_total_cost[v] = curr_cost + weight;
                    pq.push({min_total_cost[v], v});
                }
            }
        }

        return min_total_cost[n - 1] != -1 && min_total_cost[n - 1] <= k;
    }

public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> adj(n);
        int low = 0, high = 0;

        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            high = max(high, edge[2]);
        }

        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(n, adj, online, k, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};