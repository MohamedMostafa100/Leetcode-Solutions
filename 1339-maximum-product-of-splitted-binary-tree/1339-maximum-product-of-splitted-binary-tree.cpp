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
    int maxProduct(TreeNode* root) {
        long long res = 0;
        long long sum = calcSum(root);
        solve(root, sum, res);
        return res % 1000000007;
    }
private:
    long long calcSum(TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }
        long long sum = root->val;
        sum += calcSum(root->left);
        sum += calcSum(root->right);
        return sum;
    }
    long long solve(TreeNode* root, long long& sum, long long& maxProd)
    {
        if(!root)
        {
            return 0;
        }
        long long subTreeSum = root->val;
        subTreeSum += solve(root->left, sum, maxProd);
        subTreeSum += solve(root->right, sum, maxProd);
        maxProd = max(maxProd, subTreeSum * (sum - subTreeSum));
        return subTreeSum;
    }
};