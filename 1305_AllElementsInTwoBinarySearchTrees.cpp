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
    void inorder(TreeNode* root, vector<int>& list){
        if (root == NULL) return;
        inorder(root->left, list);
        list.push_back(root->val);
        inorder(root->right, list);
    }
    vector<int> merge2Arr(vector<int>& list1, vector<int>& list2){
        int i = 0, j = 0;
        vector<int> list;
        int n = list1.size(), m = list2.size();
        while (i < n || j < m){
            if (j >= m || (i < n && list1[i] <= list2[j])){
                list.push_back(list1[i++]);
            } else {
                list.push_back(list2[j++]);
            }
        }
        return list;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> list1, list2;
        inorder(root1, list1);
        inorder(root2, list2);
        return merge2Arr(list1, list2);
    }
};
