class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long sum = 0;
        int negCount = 0;
        int mini = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = matrix[i][j];

                if (val < 0)
                    negCount++;

                int absVal = abs(val);
                sum += absVal;
                mini = min(mini, absVal);
            }
        }

        // If negatives are odd, one smallest value stays negative
        if (negCount % 2 == 1) {
            sum -= 2LL * mini;
        }

        return sum;
    }
};
