class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        
        int max_log = log2(n) + 1;
        vector<vector<int>> st_max(n, vector<int>(max_log));
        vector<vector<int>> st_min(n, vector<int>(max_log));
        
        for (int i = 0; i < n; i++) {
            st_max[i][0] = nums[i];
            st_min[i][0] = nums[i];
        }
        
        for (int j = 1; j < max_log; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st_max[i][j] = max(st_max[i][j - 1], st_max[i + (1 << (j - 1))][j - 1]);
                st_min[i][j] = min(st_min[i][j - 1], st_min[i + (1 << (j - 1))][j - 1]);
            }
        }
        
        auto get_value = [&](int l, int r) -> long long {
            int len = r - l + 1;
            int k_log = log2(len);
            int mx = max(st_max[l][k_log], st_max[r - (1 << k_log) + 1][k_log]);
            int mn = min(st_min[l][k_log], st_min[r - (1 << k_log) + 1][k_log]);
            return (long long)mx - mn;
        };
        
        priority_queue<pair<long long, pair<int, int>>> pq;
        
        for (int l = 0; l < n; l++) {
            pq.push({get_value(l, n - 1), {l, n - 1}});
        }
        
        long long total_max_value = 0;
        
        for (int step = 0; step < k && !pq.empty(); step++) {
            auto top = pq.top();
            pq.pop();
            
            long long val = top.first;
            int l = top.second.first;
            int r = top.second.second;
            
            total_max_value += val;
            
            if (r > l) {
                pq.push({get_value(l, r - 1), {l, r - 1}});
            }
        }
        
        return total_max_value;
    }
};