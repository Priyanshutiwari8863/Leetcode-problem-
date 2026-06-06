class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int tSum = 0;

        for(int num : nums){
            tSum +=num; 
        }

         int lSum =0;
         int rSum = tSum;
         vector<int> answer(n);
        for(int i=0; i<n; i++){
            rSum  -=nums[i];

            answer[i]= abs(lSum - rSum);
            lSum +=nums[i];
        } 
        return answer;
        
    }
};