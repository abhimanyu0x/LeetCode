/*

Q-1605, Find Valid Matrix Given Row and Column Sums


You are given two arrays rowSum and colSum of non-negative integers where rowSum[i] is the sum of the elements in the ith row and colSum[j] is the sum of the elements of the jth column of a 2D matrix. In other words, you do not know the elements of the matrix, but you do know the sums of each row and column.

Find any matrix of non-negative integers of size rowSum.length x colSum.length that satisfies the rowSum and colSum requirements.

Return a 2D array representing any matrix that fulfills the requirements. It's guaranteed that at least one matrix that fulfills the requirements exists.

*/


class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int r = rowSum.size(); int c = colSum.size();
        vector<vector<int>>ans(r,vector<int>(c,0));
        for(int i=0; i<r; i++){
            ans[i][0]=rowSum[i];
        
        }
        for(int j=0; j<c; j++){
            long long curr_sum=0;
            for(int k=0; k<r; k++){
                curr_sum+=ans[k][j];
            }
            int k=0;
            while(curr_sum>colSum[j]){
                long long diff=curr_sum-colSum[j];
                int temp=min((long long)ans[k][j],diff);
                ans[k][j]-=temp;
                if(j+1<c)ans[k][j+1]+=temp;
                curr_sum-=temp;
                k++;
            }
        }


        return ans;
    }
};