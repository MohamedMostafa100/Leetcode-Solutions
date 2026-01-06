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
    int maxLevelSum(TreeNode* root) {
        int res = -1;
        int maxVal = INT_MIN;
        unordered_map<int, int> lvlSum;
        traverse(root, lvlSum, 1);
        for(auto& [lvl, val] : lvlSum)
        {
            if(val > maxVal)
            {
                res = lvl;
                maxVal = val;
            }
            else if(val == maxVal)
            {
                res = min(res, lvl);
            }
        }
        return res;
    }
private:
    void traverse(TreeNode* root, unordered_map<int, int>& lvlSum, int level)
    {
        if(!root)
        {
            return;
        }
        lvlSum[level] += root->val;
        traverse(root->left, lvlSum, level + 1);
        traverse(root->right, lvlSum, level + 1);
    }
};