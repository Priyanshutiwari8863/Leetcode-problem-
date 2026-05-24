class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long prefixSum = 0;
        long long maxPossible = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            prefixSum += nums[i];
            long long currentCeilAvg = (prefixSum + i) / (i + 1);
            maxPossible = max(maxPossible, currentCeilAvg);
        }
        
        return maxPossible;
    }
};