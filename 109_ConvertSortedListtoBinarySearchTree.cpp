/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    // TreeNode* createNode(int data){
    //     TreeNode* newNode = new TreeNode();
    //     newNode->val = data;
    //     newNode->left = NULL;
    //     newNode->right = NULL;
    //     return newNode;
    // }
    // ListNode* findMidNode(ListNode* head, ListNode* &prev){
    //     if (head == NULL || head->next == NULL) return head;
    //     ListNode* slow = head, *fast = head;
    //     while (fast && fast->next){
    //         prev = slow;
    //         slow = slow->next;
    //         fast = fast->next->next;
    //     }
    //     return slow;
    // }
    // TreeNode* buildBSTFromLL(ListNode* head, ListNode* tail) {
    //     if (head == NULL) return NULL;
    //     if (head == tail) return createNode(head->val);

    //     ListNode* prev = NULL;
    //     ListNode* mid = findMidNode(head, prev);
    //     prev->next = NULL;
    //     TreeNode* root = createNode(mid->val);

    //     root->left = buildBSTFromLL(head, prev);
    //     root->right = buildBSTFromLL(mid->next, tail);

    //     return root;
    // }
    // TreeNode* sortedListToBST(ListNode* head) {
    //     if (head == NULL){
    //         return NULL;
    //     } 
    //     ListNode* tail = head;
    //     while (tail->next != NULL){
    //         tail = tail->next;
    //     }
    //     return buildBSTFromLL(head, tail);
    // }

    ListNode* findMidNode(ListNode* head){
        if (head == NULL || head->next == NULL) return head;
        ListNode* slow = head, *fast = head, *prev = NULL;
        while (fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        return slow;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL){
            return NULL;
        } 
        if (!head->next) // head->next == NULL
            return new TreeNode(head->val);
        ListNode* mid = findMidNode(head);
        TreeNode* root = new TreeNode(mid->val);

        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);
        return root;
    }
};
