class Solution {
private:
    int solveOneWay(vector<pair<int, int>>& first, vector<pair<int, int>>& second) {
        int m = second.size();
        if (m == 0) return INT_MAX;

        vector<int> prefix_min_dur(m);
        prefix_min_dur[0] = second[0].second;
        for (int j = 1; j < m; ++j) {
            prefix_min_dur[j] = min(prefix_min_dur[j - 1], second[j].second);
        }

        vector<int> suffix_min_finish(m + 1, INT_MAX);
        for (int j = m - 1; j >= 0; --j) {
            suffix_min_finish[j] = min(suffix_min_finish[j + 1], second[j].first + second[j].second);
        }

        int min_total = INT_MAX;

        for (size_t i = 0; i < first.size(); ++i) {
            int f1 = first[i].first + first[i].second;

            int low = 0, high = m - 1;
            int idx = m; 
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (second[mid].first > f1) {
                    idx = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            if (idx > 0) {
                min_total = min(min_total, f1 + prefix_min_dur[idx - 1]);
            }

            if (idx < m) {
                min_total = min(min_total, suffix_min_finish[idx]);
            }
        }

        return min_total;
    }

public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, 
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();

        vector<pair<int, int>> land(n), water(m);
        for (int i = 0; i < n; ++i) land[i] = {landStartTime[i], landDuration[i]};
        for (int j = 0; j < m; ++j) water[j] = {waterStartTime[j], waterDuration[j]};

        sort(land.begin(), land.end());
        sort(water.begin(), water.end());

        return min(solveOneWay(land, water), solveOneWay(water, land));
    }
};