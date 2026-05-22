#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int count[26] = {0};
        bool visited[26] = {false};
        
        for (char c : s) {
            count[c - 'a']++;
        }
        
        string ans = "";
        
        for (char c : s) {
            count[c - 'a']--;
            
            if (visited[c - 'a']) {
                continue;
            }
            
            while (!ans.empty() && ans.back() > c && count[ans.back() - 'a'] > 0) {
                visited[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            
            ans.push_back(c);
            visited[c - 'a'] = true;
        }
        
        return ans;
    }
};