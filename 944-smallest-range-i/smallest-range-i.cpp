class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int minVal = nums[0];
        int maxVal = nums[0];
        
        for (int x : nums) {
            minVal = min(minVal, x);
            maxVal = max(maxVal, x);
        }
        
        // If the gap is already smaller than 2k, we can make the score 0
        return max(0, (maxVal - minVal) - 2 * k);
    }
};