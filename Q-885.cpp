/*
Q-885, Spiral Matrix III

You start at the cell (rStart, cStart) of an rows x cols grid facing east. The northwest corner is at the first row and column in the grid, and the southeast corner is at the last row and column.

You will walk in a clockwise spiral shape to visit every position in this grid. Whenever you move outside the grid's boundary, we continue our walk outside the grid (but may return to the grid boundary later.). Eventually, we reach all rows * cols spaces of the grid.

Return an array of coordinates representing the positions of the grid in the order you visited them.

*/

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int i = rStart, j = cStart;
        int diri = 0, dirj = 1;
        int twice = 2;
        vector<vector<int>> res;
        int moves = 1;
        int next_moves = 2;

        while (res.size() < rows * cols) {
            if (i >= 0 && i < rows && j >= 0 && j < cols) {
                res.push_back({i, j});
            }

            i += diri;
            j += dirj;
            moves -= 1;
            if (moves == 0) {
                int temp = diri;
                diri = dirj;
                dirj = -temp;
                twice -= 1;
                if (twice == 0) {
                    twice = 2;
                    moves = next_moves;
                    next_moves += 1;
                } else {
                    moves = next_moves - 1;
                }
            }
        }
        return res;
    }
};