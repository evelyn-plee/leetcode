class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
	
		vector<vector<int>> adj(numCourses);

		for (auto p : prerequisites) {
			adj[p.first].push_back(p.second);
		}

		bool hasCycle;
		
		vector<bool> onStack(numCourses, false);
		vector<bool> visited(numCourses, false);

		for (int i = 0; i < adj.size(); ++i) {
			if (!visited[i])  dfs(i, adj, hasCycle, onStack, visited);
		}

		return hasCycle ? false : true;
	}

	void dfs(int v, vector<vector<int>> &adj, bool &hasCycle, vector<bool> &onStack, vector<bool> &visited) {
		
		visited[v] = true;
		onStack[v] = true;
		for (auto &w : adj[v]) {
			if (!visited[w]) dfs(w, adj, hasCycle, onStack, visited);
			else if (onStack[w]) {
				hasCycle = true; return;
			}
		}
		onStack[v] = false;
	}
};
