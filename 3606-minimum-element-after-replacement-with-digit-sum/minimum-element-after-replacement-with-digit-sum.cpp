class Solution {
public:
    int minElement(vector<int>& nums) {
        int n= nums.size();
       int min_val =INT_MAX;

        for(int i=0; i<n;i++){
            int sum =0;
            while(nums[i]>0){
                sum += nums[i]%10;
                nums[i]=nums[i]/10;
            }
            min_val= min(min_val, sum);
            
        }
        return min_val;
        
    }
};