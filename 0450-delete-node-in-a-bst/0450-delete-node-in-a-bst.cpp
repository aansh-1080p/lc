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
    TreeNode* deleteNode(TreeNode* root, int key) {
        // 1. Base case: key not found
        if (root == NULL) {
            return NULL;
        }
        // 2. Search for the node
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        // 3. Node found
        else {
            // Case 1: No left child
            if (root->left == NULL) {
                return root->right;
            }
            // Case 2: No right child
            if (root->right == NULL) {
                return root->left;
            }
            // Case 3: Two children
            TreeNode* successor = root->right;
            // Find smallest node in right subtree
            while (successor->left != NULL) {
                successor = successor->left;
            }
            // Replace current value with successor value
            root->val = successor->val;
            // Delete the original successor node
            root->right = deleteNode(root->right, successor->val);
        }
        return root;
    }
};