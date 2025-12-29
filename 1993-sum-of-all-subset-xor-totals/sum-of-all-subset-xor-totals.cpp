class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int orAll = 0;
        for (int x : nums) {
            orAll |= x;
        }
        return orAll * (1 << (nums.size() - 1));
    }
};