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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        TreeNode* root = nullptr;
        unordered_map<int, pair<TreeNode*, bool>> nodes;
        for(int i = 0; i < descriptions.size(); i++)
        {
            TreeNode* parent = nullptr;
            TreeNode* child = nullptr;
            if(nodes.count(descriptions[i][0]))
            {
                parent = nodes[descriptions[i][0]].first;
            }
            else
            {
                parent = new TreeNode(descriptions[i][0]);
                nodes[descriptions[i][0]] = {parent, false};
            }
            if(nodes.count(descriptions[i][1]))
            {
                child = nodes[descriptions[i][1]].first;
                nodes[descriptions[i][1]].second = true;
            }
            else
            {
                child = new TreeNode(descriptions[i][1]);
                nodes[descriptions[i][1]] = {child, true};
            }
            if(descriptions[i][2] == 1)
            {
                parent->left = child;
            }
            else
            {
                parent->right = child;
            }
        }
        for(auto& it : nodes)
        {
            if(it.second.second == false)
            {
                root = it.second.first;
                break;
            }
        }
        return root;
    }
};