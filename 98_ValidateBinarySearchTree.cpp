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
    bool IsBstUtil(TreeNode* root, long long minVal, long long maxVal){
        if (root == NULL) 
            return true;

        if (root->val > minVal && root->val < maxVal
            && IsBstUtil(root->left, minVal, root->val) 
            && IsBstUtil(root->right,root->val, maxVal)){
            return true;
        }

        return false;
    }
    bool isValidBST(TreeNode* root) {
        return IsBstUtil(root, LONG_MIN, LONG_MAX);
    }
};
