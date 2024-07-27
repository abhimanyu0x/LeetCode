/*
Q-2976, Minimum Cost to Convert String I

You are given two 0-indexed strings source and target, both of length n and consisting of lowercase English letters. You are also given two 0-indexed character arrays original and changed, and an integer array cost, where cost[i] represents the cost of changing the character original[i] to the character changed[i].

You start with the string source. In one operation, you can pick a character x from the string and change it to the character y at a cost of z if there exists any index j such that cost[j] == z, original[j] == x, and changed[j] == y.

Return the minimum cost to convert the string source to the string target using any number of operations. If it is impossible to convert source to target, return -1.

Note that there may exist indices i, j such that original[j] == original[i] and changed[j] == changed[i].

*/


class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> costMatrix(26, vector<int>(26, INT_MAX));
        for(int i = 0 ; i < 26 ; i++) costMatrix[i][i] = 0;
        int szA = original.size();
        for(int i = 0 ; i < szA ; i++){
            costMatrix[original[i] - 'a'][changed[i] - 'a'] = min(costMatrix[original[i] - 'a'][changed[i] - 'a'], cost[i]);
        }

        for(int k = 0 ; k < 26 ; k++){
            for(int i = 0 ; i < 26 ; i++){
                for(int j = 0 ; j < 26 ; j++){
                    if(costMatrix[i][k] != INT_MAX && costMatrix[k][j] != INT_MAX)
                    costMatrix[i][j] = min(costMatrix[i][j], costMatrix[i][k] + costMatrix[k][j]);
                }
            }
        }

        long long costRes = 0;
        int szB = source.size();
        for(int i = 0 ; i < szB ; i++){
            if(costMatrix[source[i] - 'a'][target[i] - 'a'] == INT_MAX) return -1;
            costRes += costMatrix[source[i] - 'a'][target[i] - 'a'];
        }
        return costRes;
    }
};