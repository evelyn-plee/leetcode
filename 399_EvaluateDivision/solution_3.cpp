/*
using dfs
*/

// Time Complexity: O(e + q * e), e for number of equations and q for number of queries
// Space Complexity: O(e)

#include<unordered_map>
#include<vector>
#include<queue>
#include<unordered_set>

using namespace std;

class Solution{
public: 

    vector<double> calcEquation(vector<pair<string, string>> equations,
                                vector<double>& values,
                                vector<pair<string, string>> queries){
        vector<double> res(queries.size());
        unordered_map<string, unordered_map<string, double>> graph;
        
        for(int i = 0; i < equations.size(); ++i){
            graph[equations[i].first][equations[i].second] = values[i];
            graph[equations[i].second][equations[i].first] = 1.0/values[i];
        }

        for(int i = 0; i < queries.size(); ++i){
            unordered_set<string> visited;
            res[i] = dfs(queries[i].first, queries[i].second, visited, graph, 1.0);
        }
        return res;                        
    }

    double dfs(string from, string& to, unordered_set<string>& visited, unordered_map<string , unordered_map<string, double>>& graph, double ans){
        if(graph.count(from) == 0 || graph.count(to) == 0) return -1.0;
        if(from == to) return ans * 1.0;
    
        visited.emplace(from);
        for(auto it = graph[from].begin(); it != graph[from].end(); ++it){
            if(visited.count(it->first) != 0) continue;
            double result = dfs(it->first, to, visited, graph, ans * it->second);
            if(result != -1.0) return result;
        }
        return -1.0;
    }
};
