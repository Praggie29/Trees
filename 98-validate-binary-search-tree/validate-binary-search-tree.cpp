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
    bool isValid ( TreeNode* node , long long mini , long long maxi ) {
        if ( node == nullptr ) return true;
        if ( node -> val <= mini || node -> val >= maxi ) return false;
        return isValid ( node -> left , mini , node -> val ) && isValid ( node -> right , node -> val , maxi );
    }
    bool isValidBST(TreeNode* root) {
        return isValid(root,LLONG_MIN,LLONG_MAX);
    }
};