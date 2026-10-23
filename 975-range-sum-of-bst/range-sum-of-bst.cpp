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
    void find ( TreeNode* node , int low , int high , vector<int>&store ) {
        if ( node == nullptr ) return;
        if ( node -> val >= low && node -> val <= high ) store.push_back(node->val);
        if ( node -> val > low ) find(node->left, low, high, store);
        if (node->val < high) find(node->right, low, high, store);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int>store;
        find ( root , low , high , store );
        int sum = 0;
        for ( int i = 0 ; i < store.size() ; i ++ ) sum += store[i];
        return sum;
    }
};