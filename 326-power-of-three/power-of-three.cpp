class Solution {
public:
    bool isPowerOfThree(int n) {
        //3^19= 1162261467 is a maximum power of three in int 32-bits
        if(n > 0 && 1162261467 % n==0){
            return true;
        }else{
            return false;
        }
        
    }
};