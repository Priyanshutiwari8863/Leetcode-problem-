class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted_arr = arr;
        sort(sorted_arr.begin(), sorted_arr.end());
        
        unordered_map<int, int> rank_map;
        int rank = 1;
        
        for (int num : sorted_arr) {
            if (rank_map.find(num) == rank_map.end()) {
                rank_map[num] = rank;
                rank++;
            }
        }
        
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = rank_map[arr[i]];
        }
        
        return arr;
    }
};