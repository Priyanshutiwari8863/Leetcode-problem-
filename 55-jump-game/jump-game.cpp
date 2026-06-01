class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxre=0;
        for(int i=0;i<nums.size(); i++){
            if(i > maxre) return false;
            maxre = max(maxre, i+nums[i]);

            if( maxre >= nums.size()-1) return true;

        }
        return false;
    }
};