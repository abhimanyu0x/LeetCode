/*
1937. Maximum Number of Points with Cost
You are given an m x n integer matrix points (0-indexed). Starting with 0 points, you want to maximize the number of points you can get from the matrix.

To gain points, you must pick one cell in each row. Picking the cell at coordinates (r, c) will add points[r][c] to your score.

However, you will lose points if you pick a cell too far from the cell that you picked in the previous row. For every two adjacent rows r and r + 1 (where 0 <= r < m - 1), picking cells at coordinates (r, c1) and (r + 1, c2) will subtract abs(c1 - c2) from your score.

Return the maximum number of points you can achieve.

abs(x) is defined as:

x for x >= 0.
-x for x < 0.

*/

class Solution {
typedef long long ll;
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        vector<ll> dp(n, 0);
        vector<ll> tempdp(n, 0);

        for (int i = 0; i < n; i++) {
            dp[i] = points[0][i];
            tempdp[i] = points[0][i];
        }

        for (int i = 1; i < m; i++) {
            vector<ll> left(n, 0), right(n, 0);

            left[0] = tempdp[0];
            for (int j = 1; j < n; j++) {
                left[j] = max(left[j - 1] - 1, tempdp[j]);
            }

            right[n - 1] = tempdp[n - 1];
            for (int j = n - 2; j >= 0; j--) {
                right[j] = max(right[j + 1] - 1, tempdp[j]);
            }

            for (int j = 0; j < n; j++) {
                dp[j] = points[i][j] + max(left[j], right[j]);
            }

            tempdp = dp;
        }

        return *max_element(dp.begin(), dp.end());
    }
};
