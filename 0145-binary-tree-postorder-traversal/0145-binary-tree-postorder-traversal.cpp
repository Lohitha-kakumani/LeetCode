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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>res;
        if(root == NULL) return {};
        vector<int>right = postorderTraversal(root -> right);
        vector<int>left = postorderTraversal(root -> left);
        res.insert(res.end(),left.begin(),left.end());
        res.insert(res.end(),right.begin(),right.end());
        res.push_back(root -> val);
        return res;
    }
};