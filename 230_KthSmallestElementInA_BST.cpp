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
    void solve(TreeNode* root, int& cnt, int& k, int& ans){
        if (root == NULL) return;

        solve(root->left, cnt, k, ans);
        cnt++;
        if (cnt == k){
            ans = root->val;
            return;
        }
        solve(root->right, cnt, k, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        int cnt = 0;
        solve(root, cnt, k, ans);
        return ans;
    }
// Algorithm:
//  1. Initialize a variable, cnt = 0;
//  2. Do an Inorder traversal and instead of saving node->val in vector do a cnt++, denoting that we have encountered cnt th smallest element.
//  3. Return node->val once cnt == k.
// Complexity:
//  1. Time complexity: O(n)
//  O(n) for traversing the Tree consisting of n nodes.
//  2. Space complexity:O(1) + recursive stack space
};
