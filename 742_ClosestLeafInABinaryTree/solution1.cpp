/**
* Use DFS to construct the undirected graph, and first the start node O(n)
* Use BFS to search the graph from start node to any lead node O(n)
* Each node has most 3 edges. Time complexity: O(n), Space complexity: O(n) **/

class Solution{
public:
    int findClosestLeaf(TreeNode* root, int k){
        graph_.clear();
        start_ = NULL;
        buildGraph(root, NULL, k);
        queue<TreeNode*> q;
        q.push(start_);
        unordered_set<TreeNode*> visited;
        while(!q.empty()){
            int size = q.size();
            while(size-- >0){
                TreeNode* cur = q.front(); q.pop();
                visited.push(cur);
                if(!cur->left && !cur->right) return cur->val;
                for(TreeNode* node : graph_[cur]){
                    if(!visited.count[node]) q.push(node);
                }
            }
        }
    }
private:
    unordered_map<TreeNode*, vector<TreeNode*>> graph_;
    TreeNode* start_;
    
    void buildGraph(TreeNode* node, TreeNode* parent, int k){
        if(!node) return;
        if(node->val == k) start_ = node;
        if(parent){
            graph_[node].push_back(parent);
            graph_[parent].push_back(node);
        }
        buildGraph(node->left, node, k);
        buildGraph(node->right, node, k);
    }
};
