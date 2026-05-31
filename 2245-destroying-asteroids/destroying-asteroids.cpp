class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long curMas = mass;

        int n= asteroids.size();

        sort(asteroids.begin(),asteroids.end());

        for(int i=0; i<n;i++){ 
            if (curMas < asteroids[i]) return false;
            else{
                curMas = curMas + asteroids[i];
            }
            
        }
          return true;
        
    }
};