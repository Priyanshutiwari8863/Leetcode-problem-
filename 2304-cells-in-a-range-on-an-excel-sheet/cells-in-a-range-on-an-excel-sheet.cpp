class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> ans;
        
        char start_col = s[0];
        char start_row = s[1];
        char end_col = s[3];
        char end_row = s[4];
        
        for (char col = start_col; col <= end_col; col++) {
            for (char row = start_row; row <= end_row; row++) {
                string cell = "";
                cell += col;
                cell += row;
                ans.push_back(cell);
            }
        }
        
        return ans;
    }
};