class Solution {
public:
    
    bool isValid(int num, int t) {
        int product = 1;
        
        while (num > 0) {
            product *= (num % 10);
            num /= 10;           
        }
        
        return (product % t == 0);
    }

    int smallestNumber(int n, int t) {
        
        while (!isValid(n, t)) {
            n++;
        }
        return n; // shi number mila to usko return kiya
    }
};