#include<vector>
#include<iostream>

using namespace std;

class Solution{
public:
    bool validTree(int n, vector<pair<int, int>>& edges){
        vector<bool> visited(n, false);
        vector<vector<int>> directions(n, vector<int>());
        
        for(auto e : edges){
            directions[e.first].push_back(e.second);
            directions[e.second].push_back(e.first);
        }
        
        if(!dfs(0, -1, directions, visited)) return false;
        
        for(auto a : visited){ if(!a) return false; }
        
        return true;
    }

    bool dfs(int cur, int pre, vector<vector<int>> &dir, vector<bool> &visited){
        if(visited[cur]) return false;
        visited[cur] = true;
        for(auto a : dir[cur]){
            if(a != pre){ if(!dfs(a, cur, dir, visited)) return false; }
        }
        return true;
    }
};
