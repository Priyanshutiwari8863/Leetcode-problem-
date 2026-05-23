class Solution {
public:
    bool areNumbersAscending(string s) {
        stringstream ss(s);
        string Token;
        
        int num = -1;

        while(ss >> Token){
            if(isdigit(Token[0])){
                int cn= stoi(Token);

                if(num >= cn){
                    return false;
                }
                num = cn;
            }
        }
        return true;

    }
};