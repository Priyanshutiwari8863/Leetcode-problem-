class Solution {
public:
    bool isNumber(string s) {
        bool seenDigit = false;
        bool seenDot = false;
        bool seenE = false;
        
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            
            if (ch >= '0' && ch <= '9') {
                seenDigit = true;
            } 
            else if (ch == '+' || ch == '-') {
                if (i > 0 && s[i-1] != 'e' && s[i-1] != 'E') {
                    return false;
                }
            } 
            else if (ch == '.') {
                if (seenDot || seenE) {
                    return false;
                }
                seenDot = true;
            } 
            else if (ch == 'e' || ch == 'E') {
                if (seenE || !seenDigit) {
                    return false;
                }
                seenE = true;
                seenDigit = false;
            } 
            else {
                return false;
            }
        }
        
        return seenDigit;
    }
};