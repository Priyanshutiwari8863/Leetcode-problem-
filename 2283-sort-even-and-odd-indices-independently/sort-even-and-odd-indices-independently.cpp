class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> evenIdx, oddIdx;
        
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                evenIdx.push_back(nums[i]);
            } else {
                oddIdx.push_back(nums[i]);
            }
        }
        
        sort(evenIdx.begin(), evenIdx.end());
        sort(oddIdx.begin(), oddIdx.end(), greater<int>());
        
        int e = 0, o = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                nums[i] = evenIdx[e++];
            } else {
                nums[i] = oddIdx[o++];
            }
        }
        
        return nums;
    }
};