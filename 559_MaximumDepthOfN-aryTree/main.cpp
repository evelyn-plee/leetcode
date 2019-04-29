/*
// Definition for a Node
class Node{
public:
    int val;
    vector<Node*> children;
    
    Node(){}
    
    Node(int _val, vector<Node*> _children){
        val = _val;
        children = _children;
    }
};

class Solution{
public:
    int maxDepth(Node* root){
        int maxDepth = 0;
        maxDepthHelper(root, 0, maxDepth);
        return maxDepth
    }
    
private:
    void maxDepthHelper(Node* root, int depth, int& maxDepth){
        if(root){
            depth++;
            if(root->children.empty()) maxDepth = max(maxDepth, depth);
            for(const auto c : root->children) maxDepthHelper(c, depth, maxDepth);
        }
    }
};
