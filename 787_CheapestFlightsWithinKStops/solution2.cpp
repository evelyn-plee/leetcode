class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    unordered_map<int, vector<pair<int, int>>> graph;
    for(const auto& f : flights){
        graph[f[0]].emplace_back(f[1], f[2]);
    }
      int ans = INT_MAX;
      queue<pair<int, int>> q;
      q.push({src, 0});
      int steps = 0;
      
      while(!q.empty()){
          int size = q.size();
          while(size--){
              int curPoint = q.front().first;
              int curCost = q.front().second;
              q.pop();
              if(curPoint == dst){
                  ans = min(ans, curCost);
              }
              for(const auto& p : graph[curPoint]){
                  if(p.second + curCost > ans) continue;
                  q.push({p.first, p.second + curCost});
              }
          }
          if(steps++ > K) break;
      }
      return ans == INT_MAX ? -1 : ans;
  }
};
