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
    bool isBalanced(TreeNode* root) {
        if(checkBalance(root) == INT_MAX)
        {
            return false;
        }
        return true;
    }
private:
    int checkBalance(TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }
        int l = checkBalance(root->left);
        if(l == INT_MAX)
        {
            return l;
        }
        int r = checkBalance(root->right);
        if(abs(l - r) > 1)
        {
            return INT_MAX;
        }
        return max(l, r) + 1;
    }
};