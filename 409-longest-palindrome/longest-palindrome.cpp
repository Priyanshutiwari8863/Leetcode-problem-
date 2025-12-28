class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for (char c : s) mp[c]++;
        int len = 0;
        bool odd = false;
        for (auto &p : mp) {
            len += (p.second / 2) * 2;
            if (p.second % 2) odd = true;
        }
        return odd ? len + 1 : len;
    }
};
