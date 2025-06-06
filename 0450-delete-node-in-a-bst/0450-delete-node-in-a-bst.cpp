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
        if (!root)
            return nullptr;
        if (root->val == key) {
            if (!root->left && !root->right) {
                return nullptr;
            }
            if (root->left && !root->right) {
                return root->left;
            }
            if (!root->left && root->right) {
                return root->right;
            }
            // if both exists
            TreeNode* p = root->right;
            while (p->left)
                p = p->left;
            root->val = p->val;
            root->right = deleteNode(root->right, root->val);
            } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
            } else {
            root->right = deleteNode(root->right, key);
            }
        return root;
    }
};