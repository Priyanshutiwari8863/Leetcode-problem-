class Solution {
public:
    vector<int> evenOddBit(int n) {

         string res = "";
        while(n>0){
            if(n%2==1) res +="1";
            else res +="0";
            n=n/2;

        }
        int ecount=0; int ocount=0;
        for(int i=0;i<res.size(); i++){
            if(res[i]=='1' && i%2==0){
                ecount++;
            }
            else if(res[i]=='1'&& 1%2==1){
                ocount++;
            }
        }
        
       


        return {ecount,ocount};        
    }
};