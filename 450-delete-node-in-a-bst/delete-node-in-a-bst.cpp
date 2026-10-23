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
    void inorder ( TreeNode* node , vector<int>&store , int key ) {
        if ( !node ) return;
        inorder ( node -> left , store , key);
        if ( node -> val != key ) store.push_back(node->val);
        inorder ( node -> right , store , key);
    }
    TreeNode* sortedArrayToBST(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = sortedArrayToBST(nums, left, mid - 1);
        node->right = sortedArrayToBST(nums, mid + 1, right);
        return node;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if ( !root ) return root;
        vector<int>store;
        inorder(root,store,key);
        return sortedArrayToBST(store, 0, store.size() - 1);
    }
};