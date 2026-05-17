class Solution {
public:
    int getLucky(string s, int k) {
        int current_sum = 0;
        
        for (char c : s) {
            int val = c - 'a' + 1;
            while (val > 0) {
                current_sum += val % 10;
                val /= 10;
            }
        }
        
        k--; 
        
        while (k > 0) {
            int next_sum = 0;
            while (current_sum > 0) {
                next_sum += current_sum % 10;
                current_sum /= 10;
            }
            current_sum = next_sum;
            k--;
        }
        
        return current_sum;
    }
};