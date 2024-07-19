/*
Q-1530, Number of Good Leaf Nodes Pairs

You are given the root of a binary tree and an integer distance. A pair of two different leaf nodes of a binary tree is said to be good if the length of the shortest path between them is less than or equal to distance.

Return the number of good leaf node pairs in the tree.


*/


class Solution {
private:
    vector<int>dfs(TreeNode* &root, int &distance,int &res){
        if(!root)return {};
        if(!root->left && !root->right)return {1};
        vector<int>left=dfs(root->left,distance,res);
        vector<int>right=dfs(root->right,distance,res);
        for(auto l:left){
            for(auto r:right){
                if(l+r<=distance){
                    res++;
                }
            }
        }
        vector<int>newDistance;
        for(auto l:left){
            newDistance.push_back(l+1);
        }
        for(auto r:right){
            newDistance.push_back(r+1);
        }
        return newDistance;
    }
public:
    int countPairs(TreeNode* root, int distance) {
        int res=0;
        dfs(root,distance,res);
        return res;
    }
};