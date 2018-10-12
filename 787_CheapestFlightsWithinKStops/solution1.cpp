/**
* Using DFS; Time complexity O(n^k+1); Space complexity O(n^k+1)
*/

#include <vector>
#include <unordered_map>
#include <math>
using namespace std;

class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    graph.clear();  
    for (const auto& f : flights)
      graph[f[0]].emplace_back(f[1], f[2]);
    vector<int> visited(n, 0);
    visited[src] = 1;
    int ans = INT_MAX;
    dfs(src, dst, K + 1, 0, visited, ans);
    return ans == INT_MAX ? - 1 : ans;
  }
private:
  unordered_map<int, vector<pair<int,int>>> graph;
  
  void dfs(int src, int dst, int k, int cost, vector<int>& visited, int& ans) {
    if (src == dst) {
      ans = cost;
      return;
    }
    
    if (k == 0) return;    
    
    for (const auto& p : graph[src]) {
      if (visited[p.first]) continue; // do not visit the same city twice.
      if (cost + p.second > ans) continue; //prunning 
      visited[p.first] = 1;
      dfs(p.first, dst, k - 1, cost + p.second, visited, ans);
      visited[p.first] = 0;
    }
  }
};
