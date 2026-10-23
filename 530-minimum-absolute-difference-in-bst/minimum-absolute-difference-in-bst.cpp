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
    void minVal(TreeNode* node, int& mini, int &prevVal) {
        if (!node) return;
        minVal(node->left, mini, prevVal);
        if (prevVal != -1) {
            mini = min(mini, node->val - prevVal);
        }
        prevVal = node->val;
        minVal(node->right, mini, prevVal);
    }
    int getMinimumDifference(TreeNode* root) {
        int mini = INT_MAX;
        int prevVal = -1;
        minVal ( root , mini , prevVal );
        return mini;
    }
};