class Solution {
public:
    int minSpeedOnTime(std::vector<int>& dist, double hour) {
        int n = dist.size();
        if (hour <= n - 1) {
            return -1;
        }

        int left = 1;
        int right = 1e7;
        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canReachOnTime(dist, hour, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }

private:
    bool canReachOnTime(const std::vector<int>& dist, double hour, int speed) {
        double totalTime = 0;
        int n = dist.size();

        for (int i = 0; i < n - 1; ++i) {
            totalTime += (dist[i] + speed - 1) / speed;
        }

        totalTime += (double)dist[n - 1] / speed;

        return totalTime <= hour;
    }
};