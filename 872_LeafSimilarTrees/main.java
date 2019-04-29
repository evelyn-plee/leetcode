/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution{
   public boolean leafSimilar(TreeNode root1, TreeNode root2){
       List<Integer> leaves1 = new ArrayList();
       List<Integer> leaves2 = new ArrayList();
       dfs(root1, leaves1);
       dfs(root2, leaves2);
       return leaves1.equals(leaves2);
   } 
   
   private void dfs(TreeNode root, List<Integer> leaves){
       if(root != null){
           if(node.left == null && node.right == null) leaves.add(node.val);
           dfs(node.left, leaves);
           dfs(node.right, leaves);
       }
   }
}
