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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        if(!root)
        {
            return {};
        }
        stk.push(root);
        while(!stk.empty())
        {
            TreeNode* p = stk.top();
            while(p->left)
            {
                stk.push(p->left);
                p = p->left;
            }
            while(!stk.empty())
            {
                p = stk.top();
                res.push_back(p->val);
                stk.pop();
                if(p->right)
                {
                    stk.push(p->right);
                    break;
                }
            }
        }
        return res;
    }
};