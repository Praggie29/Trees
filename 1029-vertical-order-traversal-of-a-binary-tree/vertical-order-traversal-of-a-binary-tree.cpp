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
    
    vector<tuple<int, int, int>> nodes;
    void dfs ( TreeNode* node , int level , int col ) {
        if ( node == nullptr ) return ;

        nodes.push_back({col,level,node->val});

        dfs ( node -> left , level + 1 , col - 1 );
        dfs ( node -> right , level + 1 , col + 1 );
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        dfs ( root , 0 , 0 );
        vector<vector<int>>ans;
        if (nodes.empty()) return ans;

        sort ( nodes.begin() , nodes.end() );
        
        
        int prevCol = INT_MIN;
        for ( auto &[col, level, val] : nodes ) {
            if ( col != prevCol ) {
                ans.push_back({});
                prevCol = col;
            }
            ans.back().push_back(val);
        }
        return ans;
    }
};