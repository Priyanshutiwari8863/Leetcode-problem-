class Solution {
private:
    vector<vector<int>> children;
    vector<int> bestIndex;
    
    bool isBetter(int newIdx, int currentBestIdx, const vector<string>& wordsContainer) {
        if (currentBestIdx == -1) return true;
        
        if (wordsContainer[newIdx].length() != wordsContainer[currentBestIdx].length()) {
            return wordsContainer[newIdx].length() < wordsContainer[currentBestIdx].length();
        }
        return newIdx < currentBestIdx;
    }

    void insert(const string& word, int wordIdx, const vector<string>& wordsContainer) {
        int curr = 0;
        
        if (isBetter(wordIdx, bestIndex[curr], wordsContainer)) {
            bestIndex[curr] = wordIdx;
        }

        for (int i = word.length() - 1; i >= 0; --i) {
            int c = word[i] - 'a';
            if (children[curr][c] == 0) {
                children.push_back(vector<int>(26, 0));
                bestIndex.push_back(-1);
                children[curr][c] = children.size() - 1;
            }
            curr = children[curr][c];
            
            if (isBetter(wordIdx, bestIndex[curr], wordsContainer)) {
                bestIndex[curr] = wordIdx;
            }
        }
    }

    int query(const string& word) {
        int curr = 0;
        int lastValidBest = bestIndex[curr];

        for (int i = word.length() - 1; i >= 0; --i) {
            int c = word[i] - 'a';
            if (children[curr][c] == 0) {
                break;
            }
            curr = children[curr][c];
            lastValidBest = bestIndex[curr];
        }
        return lastValidBest;
    }

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        children.assign(1, vector<int>(26, 0));
        bestIndex.assign(1, -1);
        
        for (int i = 0; i < wordsContainer.size(); ++i) {
            insert(wordsContainer[i], i, wordsContainer);
        }
        
        vector<int> ans;
        ans.reserve(wordsQuery.size());
        for (const string& q : wordsQuery) {
            ans.push_back(query(q));
        }
        
        return ans;
    }
};