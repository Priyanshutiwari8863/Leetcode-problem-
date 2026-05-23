class Solution {
public:
    string sortSentence(string s) {
        vector<string> words(9);

        stringstream ss(s);
        string word;
        int count =0;

        while( ss >>word){
            char lastL= word.back();
            int index = lastL -'0';

            word.pop_back();
            words[index-1] = word;
            count++;
        }

        string result ="";
        for(int i =0; i<count; i++){
            result +=words[i];
            if(i < count -1 ){
                result +=" ";
            }
        }
       return result;

        
    }
};