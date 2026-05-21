class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;
       //aar1 ka sabhi pewfix ko hashset me dale
       for(int val: arr1){
          while(val>0){
              prefixes.insert(val);
              val /=10;
           }
        }
        int maxL=0;
        for(int val:arr2){
            while(val>0){
                if(prefixes.count(val)){// it return true or false mean 0 and 1;
                    int len = to_string(val).length();
                    maxL=max(len, maxL);
                    break;
                }
                val /=10;
            }
        }
        return maxL;

        
    }
};