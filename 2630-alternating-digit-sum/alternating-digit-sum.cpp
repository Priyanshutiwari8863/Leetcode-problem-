class Solution {
public:
    int alternateDigitSum(int n) {
        string s = to_string(n);
        int sum = 0;
        int sign = 1;

        for (char ch : s) {
            sum += (ch - '0') * sign;
            sign *= -1;
        }

        return sum;
    }
};