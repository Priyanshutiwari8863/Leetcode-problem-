class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";
        while(columnNumber >0){
            columnNumber--;// q ki 26 %26 ==0 hota hai to chaterter me 1 sw index sure ho rha hai

            int rem = columnNumber % 26;
            ans +=(rem + 'A');
            columnNumber /=26;
        }
        reverse(ans.begin(), ans.end());
        return ans;

    
        
    }
};