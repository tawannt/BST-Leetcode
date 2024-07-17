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
    // void dfs(TreeNode* root, TreeNode* &prevVal, int& minDiff){
    //     if (root == NULL) return;
    //     dfs(root->left, root, minDiff);
    //     if (prevVal) {
    //         minDiff = std::min(minDiff, std::abs(prevVal->val - root->val));
    //         cout << minDiff << " " << prevVal->val << " " << root->val << endl;
    //     }
    //     dfs(root->right, root, minDiff);
    // }
    TreeNode* prevVal{nullptr};
    void dfs(TreeNode* root, int& minDiff){
        if (root == NULL) return;
        dfs(root->left, minDiff);
        if (prevVal) {
            minDiff = std::min(minDiff, std::abs(prevVal->val - root->val));
        }
        prevVal = root;
        dfs(root->right, minDiff);
    }
    int getMinimumDifference(TreeNode* root) {
        int minDiff = 1000000;
        // TreeNode* prevVal = NULL;
        // dfs(root, prevVal, minDiff);
        dfs(root, minDiff);
        return minDiff;
    }
};
