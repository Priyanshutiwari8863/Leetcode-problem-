class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        
        for (int i = 2; i <= n; ++i) {
            string next_res = "";
            int len = res.length();
            
            for (int j = 0; j < len; ) {
                int count = 0;
                char current_char = res[j];
                
                while (j < len && res[j] == current_char) {
                    count++;
                    j++;
                }
                
                next_res += to_string(count) + current_char;
            }
            
            res = next_res;
        }
        
        return res;
    }
};