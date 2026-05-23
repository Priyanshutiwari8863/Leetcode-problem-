/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
        int hig = n;

        while(low <= hig){
            int mid = low +(hig - low)/2;
            int res = guess(mid);

            if(res == 0){
                return mid;
            }
            else if(res == -1){
                hig = mid-1;
            }
            else{
                low = mid +1;
            }
        }

        return -1;
    }
};