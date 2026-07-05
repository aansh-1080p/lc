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
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> rightSide;
        std::queue<TreeNode*> level, nextlevel;

        if (root == nullptr)
            return rightSide;

        level.push(root);

        while (!level.empty()) {
            TreeNode* curnode = level.front();
            if (curnode->left)
                nextlevel.push(curnode->left);
            if (curnode->right)
                nextlevel.push(curnode->right);

            level.pop();
            if (level.empty()) {
                rightSide.push_back(curnode->val);
                std::swap(level, nextlevel);
            }
        }

        return rightSide;
    }
};