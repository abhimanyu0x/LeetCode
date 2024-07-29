/*

Q-1395, Count Number of Teams


There are n soldiers standing in a line. Each soldier is assigned a unique rating value.

You have to form a team of 3 soldiers amongst them under the following rules:

Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).

*/

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        vector<int> smallest(n, 0);
        vector<int> largest(n, 0);
        for(int i = 0 ; i < n ; i++){
            for(int j = i - 1 ; j >= 0 ; j--){
                if(rating[i] > rating[j]) smallest[i]++;
                if(rating[i] < rating[j]) largest[i]++;
            }
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = i - 1 ; j >= 0 ; j--){
                if(rating[i] > rating[j]) ans += smallest[j];
                if(rating[i] < rating[j]) ans += largest[j];
            }
        }
        return ans;
    }
};