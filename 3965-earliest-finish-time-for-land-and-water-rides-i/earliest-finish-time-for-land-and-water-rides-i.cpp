class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int ans = INT_MAX; 
       
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                
              
                int landFinish1 = landStartTime[i] + landDuration[i];
                int waterStart1 = max(landFinish1, waterStartTime[j]);
                int totalTime1 = waterStart1 + waterDuration[j];
                
              
                int waterFinish2 = waterStartTime[j] + waterDuration[j];
                int landStart2 = max(waterFinish2, landStartTime[i]);
                int totalTime2 = landStart2 + landDuration[i];
                
               
                ans = min({ans, totalTime1, totalTime2});
            }
        }
        
        return ans;
        
    }
};