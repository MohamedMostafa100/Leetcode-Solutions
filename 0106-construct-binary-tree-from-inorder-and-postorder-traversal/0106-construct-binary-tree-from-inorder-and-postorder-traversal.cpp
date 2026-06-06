/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        TreeNode* root = new TreeNode(postorder[n - 1]);
        stack<TreeNode*> stk;
        stk.push(root);
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        for (int i = n - 2; i >= 0; i--) {
            if (mp[postorder[i]] > mp[stk.top()->val]) {
                TreeNode* newNode = new TreeNode(postorder[i]);
                stk.top()->right = newNode;
                stk.push(newNode);
            } else {
                TreeNode* toLeft = nullptr;
                while (!stk.empty() && mp[postorder[i]] < mp[stk.top()->val]) {
                    toLeft = stk.top();
                    stk.pop();
                }
                toLeft->left = new TreeNode(postorder[i]);
                stk.push(toLeft->left);
            }
        }
        return root;
    }
};
