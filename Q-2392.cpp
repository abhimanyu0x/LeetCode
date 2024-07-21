/*
Q-2392, Build a Matrix With Conditions

You are given a positive integer k. You are also given:

a 2D integer array rowConditions of size n where rowConditions[i] = [abovei, belowi], and
a 2D integer array colConditions of size m where colConditions[i] = [lefti, righti].
The two arrays contain integers from 1 to k.

You have to build a k x k matrix that contains each of the numbers from 1 to k exactly once. The remaining cells should have the value 0.

The matrix should also satisfy the following conditions:

The number abovei should appear in a row that is strictly above the row at which the number belowi appears for all i from 0 to n - 1.
The number lefti should appear in a column that is strictly left of the column at which the number righti appears for all i from 0 to m - 1.
Return any matrix that satisfies the conditions. If no answer exists, return an empty matrix.

*/

class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        auto topologicalSort = [](int k, const vector<vector<int>>& conditions) {
            vector<vector<int>> graph(k + 1);
            vector<int> inDegree(k + 1, 0);
            
            for (const auto& condition : conditions) {
                graph[condition[0]].push_back(condition[1]);
                inDegree[condition[1]]++;
            }
            
            queue<int> q;
            for (int i = 1; i <= k; ++i) {
                if (inDegree[i] == 0) {
                    q.push(i);
                }
            }
            
            vector<int> order;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                order.push_back(node);
                
                for (int neighbor : graph[node]) {
                    if (--inDegree[neighbor] == 0) {
                        q.push(neighbor);
                    }
                }
            }
            
            if (order.size() != k) return vector<int>();
            return order;
        };    
        vector<int> rowOrder = topologicalSort(k, rowConditions);
        vector<int> colOrder = topologicalSort(k, colConditions);   
        if (rowOrder.empty() || colOrder.empty()) return {};
        unordered_map<int, int> rowPosition;
        unordered_map<int, int> colPosition; 
        for (int i = 0; i < k; ++i) {
            rowPosition[rowOrder[i]] = i;
            colPosition[colOrder[i]] = i;
        }  
        vector<vector<int>> result(k, vector<int>(k, 0));
        for (int num = 1; num <= k; ++num) {
            int row = rowPosition[num];
            int col = colPosition[num];
            result[row][col] = num;
        }
        return result;
    }
};