/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val,List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution{
    private int maxDepth = 0;
    
    public int maxDepth(Node root){
        maxDepthHelper(root, 0);
        return maxDepth;
    }

    private void maxDepthHelper(Node root, int depth){
        if(root != null){
            depth++;
            if(root.children.isEmpty()) maxDepth = Math.max(maxDepth, depth);
            for(Node c : root.children) maxDepthHelper(c, depth);
        }
    }
}
