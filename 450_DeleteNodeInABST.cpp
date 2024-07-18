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
    TreeNode* findMinNode(TreeNode* root){
        if (root == NULL || root->left == NULL) return root;
        return findMinNode(root->left);
    } 
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;
        else if (root->val < key) root->right = deleteNode(root->right, key);
        else if (root->val > key) root->left = deleteNode(root->left, key);
        else {
            // woo... complete finding the required node
            //case 1: no child
            if (root->right == NULL && root->left == NULL){
                delete root;
                root = NULL;
            }
            //case 2: 1 child
            else if (root->right == NULL){
                TreeNode* tmp = root;
                root = root->left;
                delete tmp;
            } 
            else if (root->left == NULL){
                TreeNode* tmp = root;
                root = root->right;
                delete tmp;
            }
            //case 3: 2 children
            else {
                TreeNode* tmp = findMinNode(root->right);
                root->val = tmp->val;
                root->right = deleteNode(root->right, tmp->val);
            }
        }    
        return root;
    }
};
