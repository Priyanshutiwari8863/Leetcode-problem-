class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long firstMax = LLONG_MIN;
        long long secondMax = LLONG_MIN;
        long long thirdMax = LLONG_MIN;

        for (int num : nums) {
            if (num == firstMax || num == secondMax || num == thirdMax) {
                continue;
            }

            if (num > firstMax) {
                thirdMax = secondMax;
                secondMax = firstMax;
                firstMax = num;
            } else if (num > secondMax) {
                thirdMax = secondMax;
                secondMax = num;
            } else if (num > thirdMax) {
                thirdMax = num;
            }
        }

        return (thirdMax == LLONG_MIN) ? firstMax : thirdMax;
    }
};
