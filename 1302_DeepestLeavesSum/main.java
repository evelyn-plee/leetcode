/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

//BFS Approach
class Solution {
    public int deepestLeavesSum(TreeNode root) {
        int res = 0;
        if(root == null) return res;
        
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        while(!q.isEmpty()){
            int curSize = q.size();
            res = 0;
            for(int i = 0; i < curSize; i++){
                TreeNode curNode = q.poll();
                res += curNode.val;
                if(curNode.left != null) q.offer(curNode.left);
                if(curNode.right != null) q.offer(curNode.right);
            }
        }
        return res;
    }
}


// DFS Approach

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
    
    private int maxDepth = 0;
    private int sum = 0;
    
    public int deepestLeavesSum(TreeNode root) {
        if(root == null) return 0;
        dfs(root, 1);
        return sum;
    }
    
    private void dfs(TreeNode root, int curDepth){
        if(root == null) return;
        
        if(curDepth == maxDepth) sum += root.val;
        if(curDepth > maxDepth){
            sum = root.val;
            maxDepth = curDepth;
        }
        
        dfs(root.left, curDepth + 1);
        dfs(root.right, curDepth + 1);
    }
}
