class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for (int n : nums) {
            vector<int> divisors;

            for (int i = 1; i * i <= n; i++) {
                if (n % i == 0) {
                    divisors.push_back(i);
                   //yadi i divide that to n/i !=i to add kiya q ki dublicate na ho  
                    if (i != n / i)
                        divisors.push_back(n / i);

                    // yadi 4 divisor na ho to
                    if (divisors.size() > 4)
                        break;
                }
            }
           //yadi 4 divisor ho to 
            if (divisors.size() == 4) {
                int sum = 0;
                for (int d : divisors)
                    sum += d;
                ans += sum;
            }
        }

        return ans;
    }
};
