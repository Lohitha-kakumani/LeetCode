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
    bool sameTree(TreeNode* root,TreeNode* subRoot ){
        if(!root || !subRoot){
            return root == NULL && subRoot == NULL;
        }
        else if(root -> val == subRoot -> val){
            return sameTree(root -> left, subRoot -> left) && sameTree(root -> right, subRoot -> right); 
        }
        else{
            return false;
        }
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        else if (sameTree(root,subRoot)){
            return true;
        }
        else{
            return isSubtree(root -> left, subRoot) || isSubtree(root -> right, subRoot);
        }
    }
};