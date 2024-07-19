/*
Q-1380, Lucky Numbers in a Matrix

Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.

A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.



*/

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int>ans;
        for(int i=0; i<matrix.size(); i++){
            int row=INT_MAX;
            int col=0;
            int colIndex=0;
            for(int j=0; j<matrix[i].size(); j++){
                if(row>matrix[i][j]){
                    row=matrix[i][j];
                    colIndex=j;
                }
            }
            for(int k=0; k<matrix.size(); k++){
                if(col<matrix[k][colIndex]){
                    col=matrix[k][colIndex];
                }
            }
            if(row==col){
                ans.push_back(row);
            }
        }
        return ans;
    }
};