class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        if (timePoints.size() > 1440) return 0;

        vector<int> minutes;
        for (const string& time : timePoints) {
            int h = stoi(time.substr(0, 2));
            int m = stoi(time.substr(3, 2));
            minutes.push_back(h * 60 + m);
        }

        sort(minutes.begin(), minutes.end());

        int minDiff = INT_MAX;
        for (int i = 1; i < minutes.size(); i++) {
            minDiff = min(minDiff, minutes[i] - minutes[i - 1]);
        }

        int circularDiff = (1440 - minutes.back()) + minutes[0];
        minDiff = min(minDiff, circularDiff);

        return minDiff;
    }
};