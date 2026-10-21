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
    int maxi = INT_MIN;
    int pathSum ( TreeNode* node ) {
        if ( node == nullptr ) return 0;
        int left = max( 0, pathSum ( node -> left ));
        int right =  max( 0, pathSum ( node -> right ));
        maxi = max ( maxi , node -> val + left + right );
        return node -> val + max ( left , right );
    }
    int maxPathSum(TreeNode* root) {
        pathSum ( root );
        return maxi;
    }
};