class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int n= nums.size();
        int sum1=0;
        int sum2=0;
        for(int i=0;i<n;i++){
            int m=nums[i]; 
            if(to_string(m).length()==2){
                sum2 +=m;
            }
            else if(to_string(m).length()==1){
                sum1 +=m;
            }

        }
        if(sum1 == sum2) return false;
        else return true;

        
    }
};