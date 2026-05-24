class Solution {
public:
    long long minimumTime(std::vector<int>& time, int totalTrips) {
        long long low = 1;
        long long min_time = *std::min_element(time.begin(), time.end());
        long long high = min_time * totalTrips;
        long long ans = high;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long trips_formed = 0;
            
            for (int t : time) {
                trips_formed += mid / t;
            }
            
            if (trips_formed >= totalTrips) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
 };