class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        int base = n - 1;
        
        if (base <= 0) return false;

        vector<int> count(n, 0); 

        for (int num : nums) {
            if (num < 1 || num > base) return false;
            count[num]++;
        }

        for (int i = 1; i < base; i++) {
            if (count[i] != 1) return false;
        }

        return count[base] == 2;
    }
};