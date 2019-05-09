class Solution {
    public int maxAncestorDiff(TreeNode root) {
        return dfs(root, root.val, root.val);
    }
    
    private int dfs(TreeNode n, int mn, int mx){
        if(n == null) return mx - mn;
        mn = Math.min(mn, n.val);
        mx = Math.max(mx, n.val);
        return Math.max(dfs(n.left, mn, mx), dfs(n.right, mn, mx));
    }
}
