/**
Build Graph + BFS
1. Build an undirected graph from the tree
2. Traverse the graph from target 
3. Collect all nodes that are K steps from target

Time Complexity:O(n)
Time Complexity:O(n)
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class Solution{
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K){
        buildGraph(nullptr, root);
        
        vector<int> ans;
        
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        visited.insert(target);
        q.push(target);
        int k = 0;
        while(!q.empty() && k <= K){
            int s = q.size();
            while(s--){
                TreeNode* node = q.front(); q.pop();
                if(k == K) ans.push_back(node->val);
                for(TreeNode* child : g[node]){
                    if(visited.count(child)) continue;
                    q.push(child);
                    visited.insert(child);
                }
            }
            k++;
        }
        return ans;
    }

private:
    unordered_map<TreeNode*, vector<TreeNode*>> g;
    
    void buildGraph(TreeNode* parent, TreeNode* child){
        if(parent){
            g[parent].push_back(child);
            g[child].push_back(parent);
        }
        if(child->left) buildGraph(child, child->left);
        if(child->right) buildGraph(child, child->right);
    }
};
