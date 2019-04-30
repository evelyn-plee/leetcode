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
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> paths = new ArrayList<>();
        StringBuilder path = new StringBuilder();
        constructPaths(root, path, paths);
        return paths;
    }
    
    private void constructPaths(TreeNode root, StringBuilder path, List<String> paths){
        if(root == null) return;
        
        int len = path.length();
        path.append(root.val);
        if(root.left == null && root.right == null){
            paths.add(path.toString());
        }else{
            path.append("->");
            constructPaths(root.left, path, paths);
            constructPaths(root.right, path, paths);
        }
        path.setLength(len);
    }
}
