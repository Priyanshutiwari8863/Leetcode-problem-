class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int eleSum = 0;
        int digSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            eleSum += nums[i];

            if (nums[i] < 10) {
                digSum += nums[i];
            } else {
                int num = nums[i];

                while (num > 0) {
                    digSum += num % 10;
                    num /= 10;
                }
            }
        }

        return std::abs(eleSum - digSum);
    }
};