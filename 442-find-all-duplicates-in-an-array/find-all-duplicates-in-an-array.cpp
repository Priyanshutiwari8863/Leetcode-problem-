class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> counts;
        vector<int> result;

        for (int num : nums) {
            counts[num]++;
            if (counts[num] == 2) {
                result.push_back(num);
            }
        }

        return result;
    }
};