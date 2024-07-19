/*

Q-1110, Delete Nodes And Return Forest

Given the root of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

Return the roots of the trees in the remaining forest. You may return the result in any order.

*/

class Solution {
private:
    TreeNode* dfs(TreeNode* &root,set<int>&s,vector<TreeNode*>&ans){
        if(!root){
            return NULL;
        }
        root->left=dfs(root->left,s,ans);
        root->right=dfs(root->right,s,ans);
        if(s.find(root->val)!=s.end()){
            if(root->left) ans.push_back(root->left);
            if(root->right) ans.push_back(root->right);
            return NULL;
        }
        return root;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*>ans;
        set<int> s(to_delete.begin(), to_delete.end());
        if(s.find(root->val)==s.end())ans.push_back(root);
        root=dfs(root,s,ans);
        return ans;
    }
};