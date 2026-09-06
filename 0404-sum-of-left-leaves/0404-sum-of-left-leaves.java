class Solution {
    int sum=0;
    public int sumOfLeftLeaves(TreeNode root) {
        dfs(root,0);
        return sum;
    }
    public void dfs(TreeNode root,int flag){
        if(flag==1&&(root.left==null && root.right==null)){
            sum+=root.val;
            return;
        }
        if(root.left!=null){
            dfs(root.left,1);
        }
        if(root.right!=null){
            dfs(root.right,0);
        }
    }
}