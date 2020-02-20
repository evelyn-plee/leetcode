/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public int sumEvenGrandparent(TreeNode root) {
        return helper(root, 1, 1);
    }
    
    private int helper(TreeNode node, int p, int gp){
        if(node == null) return 0;
        return helper(node.left, node.val, p) +
               helper(node.right, node.val, p) +
               (gp % 2 == 0 ? node.val : 0);
    }
}
