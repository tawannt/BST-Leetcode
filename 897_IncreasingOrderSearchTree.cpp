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
//     void dfs(TreeNode* root, vector<int>& val){
//         if (root == NULL) return;
//         dfs(root->left, val);
//         val.push_back(root->val);
//         dfs(root->right, val);
//     }
//     TreeNode* createNode(int val){
//         TreeNode* newNode = new TreeNode();
//         newNode->val = val;
//         newNode->left = NULL;
//         newNode->right = NULL;
//         return newNode;
//     }
//     TreeNode* addTree(vector<int> val){
//         TreeNode* newTree = new TreeNode();
//         TreeNode* cur = newTree;
//         for (int i = 0; i < val.size(); i++){
//             cur->right = createNode(val[i]);
//             cur = cur->right;
//         }
//         return newTree->right;
//     }
    // void rightRotate(TreeNode* parent, TreeNode* node) {
    //     TreeNode* tmp = node->left;
    //     node->left = tmp->right;
    //     tmp->right = node;
    //     parent->right = tmp;
    // }
    // // Function to perform a left rotation
    // void leftRotate(TreeNode* parent, TreeNode* node) {
    //     TreeNode* tmp = node->right;
    //     node->right = tmp->left;
    //     tmp->left = node;
    //     parent->right = tmp;
    // }
    // // Function to perform a series of left rotations to balance the vine
    // void makeRotations(TreeNode* vineHead, int count) {
    //     TreeNode* current = vineHead;
    //     for (int i = 0; i < count; ++i) {
    //         TreeNode* tmp = current->right;
    //         leftRotate(current, tmp);
    //         current = current->right;
    //     }
    // }

    // TreeNode* increasingBST(TreeNode* root) {
    //     if (!root) return nullptr;
    //     // Step 1: Create the backbone (vine)
    //     // Temporary dummy node
    //     TreeNode* vineHead = new TreeNode(0);
    //     vineHead->right = root;
    //     TreeNode* current = vineHead;
    //     while (current->right) {
    //         if (current->right->left) {
    //             rightRotate(current, current->right);
    //         } else {
    //             current = current->right;
    //         }
    //     }
    //     return vineHead->right;
    // }
    // TreeNode* increasingBST(TreeNode* root) {
    //     vector<int> val;
    //     dfs(root, val);
    //     return addTree(val);
    // }
    TreeNode* increasingBST(TreeNode* root, TreeNode* tail = NULL) {
        if (!root) return tail;
        TreeNode* res = increasingBST(root->left, root);
        root->left = NULL;
        root->right = increasingBST(root->right, tail);
        return res;

    }
};
