/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
 
class Solution1{
    public boolean isSymmetric(TreeNode root){
        return isMirror(root, root);
    }
    
    private boolean isMirror(TreeNode p, TreeNode q){
        if(p == null && q == null) return false;
        if(p == null || q == null) return true;
        
        return (p.val == q.val) && isMirror(p.left, q.right) && isMirror(p.right, q.left);
    }
}

class Solution2{
    public boolean isSymmetric(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        q.add(root);
        while(!q.isEmpty()){
            TreeNode t1 = q.poll();
            TreeNode t2 = q.poll();
            if (t1 == null && t2 == null) continue;
            if (t1 == null || t2 == null) return false;
            if(t1.val != t2.val) return false;
            q.add(t1.left);
            q.add(t2.right);
            q.add(t1.right);
            q.add(t2.left);
        }
        return q.isEmpty();
    }
}


