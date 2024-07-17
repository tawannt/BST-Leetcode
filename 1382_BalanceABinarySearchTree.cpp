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
    // void createArray(TreeNode* root, vector<TreeNode*>& arr){
    //     if (root == NULL) return;
    //     createArray(root->left, arr);
    //     arr.push_back(root);
    //     createArray(root->right, arr);
    // }
    // TreeNode* buildTree(vector<TreeNode*> arr, int start, int end){
    //     if (start > end) return NULL;
    //     int mid = (start + end) / 2;
    //     TreeNode* root = arr[mid];
    //     root->left = buildTree(arr, start, mid - 1);
    //     root->right = buildTree(arr, mid + 1, end);

    //     return root;
    // }

    // TreeNode* balanceBST(TreeNode* root) {
    //     vector<TreeNode*> arr;
    //     createArray(root, arr);
    //     int n = arr.size();
    //     return buildTree(arr, 0, n - 1);
    // }
    void createArray(TreeNode* root, vector<int>& arr){
        if (root == NULL) return;
        createArray(root->left, arr);
        arr.push_back(root->val);
        createArray(root->right, arr);
    }
    TreeNode* buildTree(vector<int>& arr, int start, int end){
        if (start > end) return NULL;
        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = buildTree(arr, start, mid - 1);
        root->right = buildTree(arr, mid + 1, end);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        createArray(root, arr);
        int n = arr.size();
        return buildTree(arr, 0, n - 1);
    }
};
