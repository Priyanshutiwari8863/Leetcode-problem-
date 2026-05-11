class Solution {
public:
    vector<int> buildSPF(int mx) {
        vector<int> spf(mx + 1);
        for (int i = 2; i <= mx; i++) {
            if (spf[i] == 0) {
                spf[i] = i;
                if (1LL * i * i <= mx) {
                    for (long long j = 1LL * i * i; j <= mx; j += i) {
                        if (spf[j] == 0) spf[j] = i;
                    }
                }
            }
        }
        return spf;
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        int mx = *max_element(nums.begin(), nums.end());
        vector<int> spf = buildSPF(mx);

        unordered_map<int, vector<int>> bucket;

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            while (x > 1) {
                int p = spf[x];
                bucket[p].push_back(i);
                while (x % p == 0) x /= p;
            }
        }

        vector<bool> vis(n, false);
        queue<int> q;
        q.push(0);
        vis[0] = true;

        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                int i = q.front();
                q.pop();

                if (i == n - 1) return steps;

                if (i > 0 && !vis[i - 1]) {
                    vis[i - 1] = true;
                    q.push(i - 1);
                }

                if (i + 1 < n && !vis[i + 1]) {
                    vis[i + 1] = true;
                    q.push(i + 1);
                }

                int val = nums[i];

                if (val >= 2 && spf[val] == val) {
                    auto it = bucket.find(val);
                    if (it != bucket.end()) {
                        for (int idx : it->second) {
                            if (!vis[idx]) {
                                vis[idx] = true;
                                q.push(idx);
                            }
                        }
                        bucket.erase(it);
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};