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
    void inorderAdd(TreeNode* root, vector<int>& a){
        if (root == NULL) return;
        inorderAdd(root->left, a);
        a.push_back(root->val);
        cout << root->val << " ";
        inorderAdd(root->right, a);
    }
    void inorder(TreeNode* root, vector<int>& a, int& i){
        if (root == NULL) return;
        inorder(root->left, a, i);
        root->val = a[i++];
        inorder(root->right, a, i);
    }
    void recoverTree(TreeNode* root) {
        vector<int> a;
        inorderAdd(root, a);
        sort(a.begin(), a.end());
        int i = 0;
        inorder(root, a, i);
    }
};
