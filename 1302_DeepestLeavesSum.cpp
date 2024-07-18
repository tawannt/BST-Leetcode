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
    int maxDepth(TreeNode* root){
        if (root == NULL) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
    int solve(TreeNode* &root, int depth){
        if (root == NULL) return 0;
        --depth;
        if (depth == 0) return root->val;
        int l = 0, r = 0;
        l = solve(root->left, depth);
        r = solve(root->right, depth);
        return l + r;
    }
    int deepestLeavesSum(TreeNode* root) {
        if (root == NULL) return 0;
        int maxD = maxDepth(root);
        int ans = 0;
        ans = solve(root, maxD);
        return ans;
    }
};
