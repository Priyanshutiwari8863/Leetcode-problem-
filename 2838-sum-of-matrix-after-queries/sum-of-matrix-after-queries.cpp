class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        long long totalSum = 0;
        
        unordered_set<int> seenRows;
        unordered_set<int> seenCols;
        
        for (int i = queries.size() - 1; i >= 0; --i) {
            int type = queries[i][0];
            int index = queries[i][1];
            long long val = queries[i][2];
            
            if (type == 0) {
                if (seenRows.find(index) == seenRows.end()) {
                    totalSum += val * (n - seenCols.size());
                    seenRows.insert(index);
                }
            } else {
                if (seenCols.find(index) == seenCols.end()) {
                    totalSum += val * (n - seenRows.size());
                    seenCols.insert(index);
                }
            }
            
            if (seenRows.size() == n || seenCols.size() == n) {
                break;
            }
        }
        
        return totalSum;
    }
};