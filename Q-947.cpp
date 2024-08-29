/*
947. Most Stones Removed with Same Row or Column

On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.

*/
#include <vector>
using namespace std;

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> visited(n, false);
        int numComponents = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                numComponents++;
                visited[i] = true;
                vector<int> stack = {i};

                while (!stack.empty()) {
                    int current = stack.back();
                    stack.pop_back();
                    for (int j = 0; j < n; j++) {
                        if (!visited[j] && (stones[current][0] == stones[j][0] || stones[current][1] == stones[j][1])) {
                            visited[j] = true;
                            stack.push_back(j);
                        }
                    }
                }
            }
        }

        return n - numComponents;
    }
};
