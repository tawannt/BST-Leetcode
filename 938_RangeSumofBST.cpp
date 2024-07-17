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
    void dfs(TreeNode* root, int low, int high, int& res){
        if (root == NULL) return;
        if (root->val >= low && root->val <= high) res += root->val;
        dfs(root->left, low, high, res);
        dfs(root->right, low, high, res);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {  
        ios::sync_with_stdio(0);
        cin.tie(0);
        int res = 0;
        dfs(root, low, high, res);
        return res;
    }
    // int rangeSumBST(TreeNode* root, int low, int high) {  
    //     ios::sync_with_stdio(0);
    //     cin.tie(0);
    //     int res = 0;
    //     if(root == NULL) return 0;
    //     if (root->val >= low && root->val <= high) res += root->val;
    //     if (root->val >= low) res += rangeSumBST(root->left, low, high);
    //     if (root->val <= high)res += rangeSumBST(root->right, low, high);
    //     return res;
    // }
};
