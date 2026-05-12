class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        if(n<=2 ) return n;
        int maxL=2;
        int currL =2;

      for(int i=2;i<n;i++){
        if(nums[i]== nums[i-1] + nums[i-2]){
            currL++;
        }
        else{
            currL=2;
        }
        maxL=max(maxL,currL);
      }
        return maxL;
    }
};