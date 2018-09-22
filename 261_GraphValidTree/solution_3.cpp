#include<vector>
#include<iostream>
#include<unordered_set>
#include<queue>

using namespace std;

class Solution{
public:
    bool validTree(int n , vector<pair<int, int>>& edges){
        vector<unordered_set<int>> dir(n, unordered_set<int>());
        unordered_set<int> visited{{0}};
        queue<int> q{{0}};
        for(auto e : edges){
            dir[e.first].insert(e.second);
            dir[e.second].insert(e.first);
        }
        
        while(!q.empty()){
            int tmp = q.front(); q.pop();
            for(auto a : dir[tmp]){
                if(visited.count(a)) return false;
                visited.insert(a);
                q.push(a);
                dir[a].erase(tmp);
            }
        }
        return visited.size() == n;
    }
};
