/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class DFS_Solution {
    List<Integer> res = new ArrayList();
    public List<Integer> largestValues(TreeNode root) {
        dfs(root, 1);
        return res;
    }
    
    private void dfs(TreeNode cur, int depth){
        if(cur == null) return;
        if(depth > res.size()) res.add(cur.val);
        else res.set(depth-1, Math.max(cur.val, res.get(depth-1)));
        dfs(cur.left, depth + 1);
        dfs(cur.right, depth + 1);
    }
}
