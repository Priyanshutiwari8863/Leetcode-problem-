class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        int minVal = nums[0];
        int maxVal = nums[0];
        for (int num : nums) {
            minVal = min(minVal, num);
            maxVal = max(maxVal, num);
        }

        if (minVal == maxVal) return 0;

        int bucketSize = max(1, (maxVal - minVal) / (n - 1));
        int bucketCount = (maxVal - minVal) / bucketSize + 1;

        vector<int> bucketMin(bucketCount, INT_MAX);
        vector<int> bucketMax(bucketCount, INT_MIN);

        for (int num : nums) {
            int bucketIdx = (num - minVal) / bucketSize;
            bucketMin[bucketIdx] = min(bucketMin[bucketIdx], num);
            bucketMax[bucketIdx] = max(bucketMax[bucketIdx], num);
        }

        int maxGap = 0;
        int previousMax = minVal;

        for (int i = 0; i < bucketCount; i++) {
            if (bucketMin[i] == INT_MAX) continue; 
            
            maxGap = max(maxGap, bucketMin[i] - previousMax);
            previousMax = bucketMax[i];
        }

        return maxGap;
    }
};


