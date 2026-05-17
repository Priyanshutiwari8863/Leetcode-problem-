class Solution {
public:
    bool checkDivisibility(int n) {
       int M =n;
        int sum =0;
        int Tsum=0;
        int products =1;
        while(n>0){
            int dig=n%10;
            sum +=dig;
            products *=dig;
            
            n = n/10;
        }
         Tsum = sum + products;
         return(M % Tsum ==0);
    }
};