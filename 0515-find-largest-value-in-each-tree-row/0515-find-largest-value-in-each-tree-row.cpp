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

    void helper(vector<int>& res, TreeNode* root, int length){
        if(root == nullptr)return ;
        if(res.size() == length)res.push_back(root -> val);
        else res[length] = max(res[length], root->val);
        helper(res,root -> left, length+1);
        helper(res,root -> right, length+1);

    }
    vector<int> largestValues(TreeNode* root) {
        vector<int>res;
        helper(res,root, 0);
        return res;
    }
};