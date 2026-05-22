class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long ans =0;
        for(char c : columnTitle){
            int val = c - 'A' +1;// formula for finding char val;
            ans = ans*26 + val;
        }
        return ans;
        
    }
};