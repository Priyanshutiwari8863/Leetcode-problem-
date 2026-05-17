class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        q.push(start);
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            if (arr[curr] == 0) {
                return true;
            }
            
            if (arr[curr] < 0) {
                continue;
            }
            
            int right = curr + arr[curr];
            int left = curr - arr[curr];
            
            arr[curr] = -arr[curr]; 
            
            if (right < arr.size()) {
                q.push(right);
            }
            if (left >= 0) {
                q.push(left);
            }
        }
        
        return false;
    }
};