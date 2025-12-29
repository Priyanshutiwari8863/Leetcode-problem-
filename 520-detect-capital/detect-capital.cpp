class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt = 0, n = word.size();
        for (char c : word) 
            if (isupper(c)) cnt++;
        return cnt == 0 || cnt == n || (cnt == 1 && isupper(word[0]));
    }
};
