/*
840. Magic Squares In Grid

A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

Given a row x col grid of integers, how many 3 x 3 contiguous magic square subgrids are there?

Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.

*/

class Solution {
public:
    bool contain_same_sum(vector<vector<int>>&grid,int start_row,int start_col){
        map<int,int>mpp;
        vector<int>row_col_dia_sum;
        for(int i=start_row;i<start_row+3;i++){
            int sum=0;
            for(int j=start_col;j<start_col+3;j++){
                if(mpp.find(grid[i][j])!=mpp.end() || grid[i][j]<1 || grid[i][j]>9){
                    return false;
                }
                sum+=grid[i][j];
                mpp[grid[i][j]]=i;
            }
            row_col_dia_sum.push_back(sum);
        }

         for(int i=start_col;i<start_col+3;i++){
            int sum=0;
            for(int j=start_row;j<start_row+3;j++){
                sum+=grid[j][i];
            }
            row_col_dia_sum.push_back(sum);
        }

        int sum=grid[start_row][start_col]+grid[start_row+1][start_col+1]+grid[start_row+2][start_col+2];
        row_col_dia_sum.push_back(sum);

        sum=grid[start_row][start_col+2]+grid[start_row+1][start_col+1]+grid[start_row+2][start_col];
        row_col_dia_sum.push_back(sum);

        int same=row_col_dia_sum[0];
        for(int i=1;i<row_col_dia_sum.size();i++){
            if(row_col_dia_sum[i]!=same){
                return false;
            }
        }

        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        for(int i=0;i<=m-3;i++){
            for(int j=0;j<=n-3;j++){
                if(contain_same_sum(grid,i,j)){
                    count++;
                }
            }
        }

        return count;


    }
};