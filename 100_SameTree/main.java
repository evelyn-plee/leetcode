/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Iterative_Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if (p == null && q == null) return true;
        if (p == null || q == null) return false;
        Stack<TreeNode> stackP = new Stack<>();
        Stack<TreeNode> stackQ = new Stack<>();
        stackP.push(p);
        stackQ.push(q);
        while (!stackP.empty() && !stackQ.empty()) {
            TreeNode np = stackP.pop();
            TreeNode nq = stackQ.pop();
            if (np.val != nq.val) return false;
            if (np.left != null && nq.left != null) {
                stackP.push(np.left);
                stackQ.push(nq.left);
            } else if (np.left != null || nq.left != null) {
                return false;
            }
            if (np.right != null && nq.right != null) {
                stackP.push(np.right);
                stackQ.push(nq.right);
            } else if (np.right != null || nq.right != null) {
                return false;
            }
        }
        return true;
    }
}

class Recursive_Solution{
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if (p == null && q == null) return true;
        if (q == null || p == null) return false;
        if (p.val != q.val) return false;
        return isSameTree(p.right, q.right) && isSameTree(p.left, q.left);
    }
}
