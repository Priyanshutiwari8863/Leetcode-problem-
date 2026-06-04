class Solution {
public:
    long long smallestNumber(long long num) {
        if (num == 0) return 0;
        
        
        bool isNegative = num < 0;
        
       
        std::string s = std::to_string(std::abs(num));
        
        if (isNegative) {
            
            std::sort(s.begin(), s.end(), std::greater<char>());
            return - stoll(s);
        } else {
            
            sort(s.begin(), s.end());
            
            
            if (s[0] == '0') {
                size_t first_non_zero = s.find_first_not_of('0');
                std::swap(s[0], s[first_non_zero]);
            }
            return stoll(s);
        }
    }
};