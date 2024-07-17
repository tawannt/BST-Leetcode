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
class Solution {
public:
    void solve(TreeNode* root, int targetSum, vector<vector<int>>& res, vector<int> paths){
        if (root == NULL) return;
        targetSum -= root->val;
        paths.push_back(root->val);
        if(!root->left && !root->right && targetSum == 0){
            res.push_back(paths);
            return;
        } 
        solve(root->left, targetSum, res, paths);
        solve(root->right, targetSum, res, paths);
        paths.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> paths;
        solve(root, targetSum, res, paths);
        return res;
    }
};
