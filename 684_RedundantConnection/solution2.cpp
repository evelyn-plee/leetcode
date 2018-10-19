// Use DFS - for each edge (u,v), check if (u,v) are already connected O(n^2)

class Solution{
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges){
        unordered_map<int, vector<int>> graph;
        for(const auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            
            unordered_set<int> visited;
            if(hasPath(u, v, graph, visited)) return edge;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        return {};
    }
private:
    bool hasPath(int cur, int goal, unordered_map<int, vector<int>>& graph, unordered_set<int>& visited){
        if(cur == goal) return true;
        visited.insert(cur);
        if(!graph.count(cur) || !graph.count(goal)) return false;
        for(int next : graph[cur]){
            if(visited.count(next)) continue;
            if(hasPath(next, goal, graph, visited)) return true;
        }
        return false;
    }
};
