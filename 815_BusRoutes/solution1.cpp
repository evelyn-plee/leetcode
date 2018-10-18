// Use BFS, time complexity:O(mn), space complexity:O(mn)

class Solution{
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T){
        if(S == T) return 0;
        
        unordered_map<int, vector<int>> m;
        for(int i = 0; i < routes.size(); ++i)
            for(const int stop : routes[i])
                m[stop].push_back(i);
                
         queue<int> q; 
         q.push(S);
         vector<int> visited(routes.size(), 0);
         int buses = 0;
         
         while(!q.empty()){
            int size = q.size();
            ++buses;
            while(size--){
                int cur = q.front(); q.pop();
                for(const int bus : m[cur]){
                    if(visited[bus]) continue;
                    visited[bus] = 1;
                    for(int nextStop : routes[bus]){
                        if(nextStop == T) return buses;
                        q.push(stop);
                    }
                }
            }
         }
        return -1;
    }
};
