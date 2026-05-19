class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;
        vector<int> result;
        int n= nums.size();

        for(int num: nums){
            counts[num]++;
        }
        for(auto i : counts){
            if(i.second > n / 3){
                result.push_back(i.first);
            }
        }
      return result;   
    }
};