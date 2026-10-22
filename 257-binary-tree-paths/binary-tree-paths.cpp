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
    void rootToLeafPaths ( TreeNode* root , vector<string>&ans , string s ) {
        if (!root) return;
        string currentPath = s.empty() ? to_string(root->val) : s + "->" + to_string(root->val);
        if ( root -> left == nullptr && root -> right == nullptr ) {
            ans.push_back(currentPath);
            return;
        }
        rootToLeafPaths ( root -> left , ans ,currentPath );
        rootToLeafPaths ( root -> right , ans , currentPath );
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        rootToLeafPaths ( root , ans , "" );
        return ans;
    }
};