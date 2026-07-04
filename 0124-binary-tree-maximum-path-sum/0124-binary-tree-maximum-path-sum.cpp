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
    int maxi = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxi;
    }
private:
    int solve(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        int left = max(solve(node->left), 0);
        int right =max(solve(node->right), 0);
        maxi =max(maxi, node->val + left + right);
        return max(left, right) + node->val;
    }
};
