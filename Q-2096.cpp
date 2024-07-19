/*

Q-2096, Step-By-Step Directions From a Binary Tree Node to Another


You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. You are also given an integer startValue representing the value of the start node s, and a different integer destValue representing the value of the destination node t.

Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:

'L' means to go from a node to its left child node.
'R' means to go from a node to its right child node.
'U' means to go from a node to its parent node.
Return the step-by-step directions of the shortest path from node s to node t.



*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
    bool dfs(TreeNode* root, int target, string &path) {
        if (!root) return false;
        if (root->val == target) return true;
        path.push_back('L');
        if (dfs(root->left, target, path)) return true;
        path.pop_back();
        path.push_back('R');
        if (dfs(root->right, target, path)) return true;
        path.pop_back();
        return false;
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string start_path, end_path;
        dfs(root, startValue, start_path);
        dfs(root, destValue, end_path); 
        int i = 0;
        while (i < min(start_path.size(), end_path.size()) && start_path[i] == end_path[i]) {
            i++;
        }
        string ans(start_path.size() - i, 'U');
        ans += end_path.substr(i);
        return ans;
    }
};