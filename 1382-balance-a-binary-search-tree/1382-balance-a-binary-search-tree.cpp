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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nums;
        inOrder(root, nums);
        int n = nums.size();
        return constructTree(nums, 0, n);
    }
private:
    void inOrder(TreeNode* root, vector<int>& nums)
    {
        if(!root)
        {
            return;
        }
        inOrder(root->left, nums);
        nums.push_back(root->val);
        inOrder(root->right, nums);
    }
    TreeNode* constructTree(vector<int>& nums, int i, int j)
    {
        if(i == j)
        {
            return nullptr;
        }
        int mid = (i + j) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = constructTree(nums, i, mid);
        root->right = constructTree(nums, mid + 1, j);
        return root;
    }
};