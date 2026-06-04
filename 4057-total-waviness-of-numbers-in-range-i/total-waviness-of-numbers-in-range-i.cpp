class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int total_sum = 0;
        
        for (int i = num1; i <= num2; ++i) {
           
            if (i < 100) continue; 
            
            string s = to_string(i);
            int n = s.length();
            
            for (int j = 1; j < n - 1; ++j) {
                // Peak condition
                if (s[j] > s[j-1] && s[j] > s[j+1]) {
                    total_sum++;
                }
                // valley condition
                else if (s[j] < s[j-1] && s[j] < s[j+1]) {
                    total_sum++;
                }
            }
        }
        
        return total_sum;
    }
};