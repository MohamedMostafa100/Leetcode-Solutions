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
    int sumRootToLeaf(TreeNode* root) {
        int res = 0;
        solve(root, 0, res);
        return res;
    }
private:
    void solve(TreeNode* root, int sum, int& res)
    {
        if(!root)
        {
            return;
        }
        if(!root->left && !root->right)
        {
            res += sum * 2 + root->val;
            return; 
        }
        solve(root->left, sum * 2 + root->val, res);
        solve(root->right, sum * 2 + root->val, res);
    }
};