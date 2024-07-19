/*

Q-2196, Create Binary Tree From Descriptions

You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,

If isLefti == 1, then childi is the left child of parenti.
If isLefti == 0, then childi is the right child of parenti.
Construct the binary tree described by descriptions and return its root.

The test cases will be generated such that the binary tree is valid.

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n=descriptions.size();
        unordered_map<int,TreeNode*>node_map;
        unordered_set<int>child_set;
        for(int i=0; i<n; i++){
            int parent=descriptions[i][0]; int child =descriptions[i][1];
            child_set.insert(child);
            if(node_map.find(parent)==node_map.end()){
                node_map[parent] = new TreeNode(parent);
            }
            if(node_map.find(child)==node_map.end()){
                node_map[child] = new TreeNode(child);
            }
            if(descriptions[i][2]==1){
                node_map[parent]->left=node_map[child];
            }else{
                node_map[parent]->right=node_map[child];
            }
        }
        int head_val=-1;
        for(int i=0; i<n; i++){
            if(child_set.find(descriptions[i][0])==child_set.end()){
                head_val=descriptions[i][0];  
            }
        }
        return node_map[head_val];
    }
};