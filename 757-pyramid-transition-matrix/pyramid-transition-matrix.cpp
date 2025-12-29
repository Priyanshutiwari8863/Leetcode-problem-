class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        // Build map from pair -> possible top blocks
        unordered_map<string, vector<char>> mp;
        for (auto &triplet : allowed) {
            mp[triplet.substr(0, 2)].push_back(triplet[2]);
        }
        unordered_set<string> memo; // store failed bottoms
        return dfs(bottom, mp, memo);
    }

private:
    bool dfs(const string &curr, unordered_map<string, vector<char>> &mp, unordered_set<string> &memo) {
        if (curr.size() == 1) return true;
        if (memo.count(curr)) return false; // already known to fail

        vector<string> nextRows;
        generateNextRows(curr, 0, "", mp, nextRows);

        for (auto &next : nextRows) {
            if (dfs(next, mp, memo)) return true;
        }

        memo.insert(curr); // mark current row as failed
        return false;
    }

    void generateNextRows(
        const string &curr,
        int idx,
        string build,
        unordered_map<string, vector<char>> &mp,
        vector<string> &nextRows
    ) {
        if (idx == (int)curr.size() - 1) {
            nextRows.push_back(build);
            return;
        }
        
        string key = curr.substr(idx, 2);
        if (mp.find(key) == mp.end()) return;

        for (char c : mp[key]) {
            generateNextRows(curr, idx + 1, build + c, mp, nextRows);
        }
    }
};
