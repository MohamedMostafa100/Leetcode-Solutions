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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        TreeNode* res = nullptr;
        int depth = -1;
        solve(root, 0, depth, res);
        return res;
    }
private:
    int solve(TreeNode* root, int level, int& depth, TreeNode*& res)
    {
        if(!root)
        {
            return 0;
        }
        int left = solve(root->left, level + 1, depth, res);
        int right = solve(root->right, level + 1, depth, res);
        if(left == right)
        {
            if(left + level >= depth)
            {
                res = root;
                depth = left + level;
            }
        }
        return max(left, right) + 1;
    }
};