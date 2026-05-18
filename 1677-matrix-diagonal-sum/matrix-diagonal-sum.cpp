class Solution {
public:
    int diagonalSum(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int sum=0;

        for(int i=0;i<n;i++){
            sum +=matrix[i][i];

            if(i != n-i-1){
                sum+=matrix[i][n-i-1];// ignor duplicate element 
            }
        }
        return sum;
        
    }
};