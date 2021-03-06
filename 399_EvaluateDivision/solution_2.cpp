/*
using bfs
*/

#include<unordered_map>
#include<vector>
#include<queue>
#include<unordered_set>

class Solution{
public: 
    vector<double> calcEquation(vector<pair<string, string>> equations,
                                vector<double>& values,
                                vector<pair<string, string>> queries){
        vector<double> res;
        unordered_map<string, unordered_map<string, double>> graph;
        for(int i = 0; i < equations.size(); ++i){
            graph[equations[i].first].emplace(equations[i].second, values[i]);
            graph[equations[i].first].emplace(equations[i].first, 1.0);
            graph[equations[i].second].emplace(equations[i].first, 1.0/values[i]);
            graph[equations[i].second].emplace(equations[i].second, 1.0);
        }
        
        for(auto query: queries){
            if(!graph.count(query.first) || !graph.count(query.second)) res.push_back(-1.0);
            else{
                queue<pair<string, double>> q;
                unordered_set<string> visited{query.first};
                q.push({query.first, 1.0});
                bool found = false;
                while(!q.empty() && !found){
                    pair<string, double> t = q.front(); q.pop();
                    if(t.first == query.second){
                        found = true;
                        res.push_back(t.second);
                        break;
                    }
                    for(auto a : graph[t.first]){
                        if(!visited.count(a.first)){
                            a.second *= t.second;
                            q.push(a);
                            visited.insert(a.first);
                        }
                    }
                }
                if(!found) res.push_back(-1.0);
            }
        }
        return res;                        
    }
};
