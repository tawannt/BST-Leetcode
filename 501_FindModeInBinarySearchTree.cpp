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
    struct StaticArray{
        int arr[2];
    };
    void dfs(TreeNode* t, vector<int> &nodes){
        if (t == NULL) {
            return;
        }
        dfs(t->left, nodes);
        nodes.push_back(t->val);
        dfs(t->right, nodes);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> nodes;
        dfs(root, nodes);
        int maxi = 0;
        int arr[1];
        vector<StaticArray> array;
        for (int i = 0; i < nodes.size(); i++){
            StaticArray a;
            a.arr[0] = nodes[i];
            int count = 1;
            for (int j = i + 1; j < nodes.size(); ++count && j++){
                if (nodes[j] != nodes[i]) break;
            }
            a.arr[1] = count;
            maxi = max(maxi, count);
            array.push_back(a);
            i += count - 1;
        }

        vector<int> res;
        for (int i = 0; i < array.size(); i++){
            if (maxi == array[i].arr[1])
                res.push_back(array[i].arr[0]);
        }
        return res;
    }
};
