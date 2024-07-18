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
    bool isSameTree(TreeNode* root, TreeNode* subRoot){
        if (root == NULL && subRoot == NULL) return true;
        else if (!root|| !subRoot) return false;
        if (root->val == subRoot->val){
            if (isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right))
                return true;
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL) return subRoot == NULL;
        if (isSameTree(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
