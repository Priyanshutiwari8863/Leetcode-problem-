class Solution {
public:
    
    int countDigits(int num) {
    if (num == 0) return 1;

    int count = 0;
    while (num > 0) {
        count++;
        num /= 10;
    }

    return count;
}
    int findNumbers(vector<int>& nums) {
       int  n = nums.size();
        int counteven=0;
        for(int i=0; i<n;i++){
            if( countDigits(nums[i])%2==0) counteven++;
            else continue;

        }

        return counteven;
    }
};