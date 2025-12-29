class Solution {
public:
    int minOperations(int n) {
        int ans = 0;
        while (n > 0) {
            // If last two bits are 11, it's better to add 1
            if ((n & 3) == 3) {
                ++n;
                ++ans;
            }
            // Else if lowest bit is 1, subtract 1
            else if (n & 1) {
                --n;
                ++ans;
            }
            // Else if last bit is 0, shift right
            else {
                n >>= 1;
            }
        }
        return ans;
    }
};
