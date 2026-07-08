class Solution {
public:
    long long sumAndMultiply(int n) {
        if (n == 0) return 0; 
        
        string s = to_string(n);
        long long newNum = 0;
        long long sum = 0;
        
        for (char c : s) {
            if (c != '0') {
                int dig = c - '0';
                sum += dig;
                newNum = (newNum * 10) + dig;
            }
        }
        
        return newNum * sum;
    }
};