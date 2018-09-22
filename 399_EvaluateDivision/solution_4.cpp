/*
using union-find
*/

#include<unordered_map>
#include<vector>
#include<unordered_set>
#include<string>

using namespace std;

class Solution{
public: 

    vector<double> calcEquation(vector<pair<string, string>> equations,
                                vector<double>& values,
                                vector<pair<string, string>> queries){
        vector<double> res(queries.size());
        unordered_map<string, pair<string, double>> graph;
        for(int i = 0; i < equations.size(); ++i){
            string a = equations[i].first;
            string b = equations[i].second;
            double val = values[i];
            if(graph.count(a) == 0 && graph.count(b) == 0){
                graph[a] = make_pair(b, val);
                graph[b] = make_pair(b, 1);
            } else if(graph.count(a) == 0){
                graph[a] = make_pair(b, graph[b].second * val);
            } else if(graph.count(b) == 0){
                graph[b] = make_pair(a, graph[a].second / val);
            } else unions(a, b, val, graph);
        }

        for(int i = 0; i < queries.size(); ++i){
            string a = queries[i].first;
            string b = queries[i].second;
            if(graph.count(a) == 0 || graph.count(b) == 0|| find(a, graph) != find(b, graph)) res[i] = -1.0;
            else res[i] = (graph[a].second/graph[b].second);
        }
        return res;                        
    }
private:
    void unions(string a, string b, double val, unordered_map<string, pair<string, double>>& graph){
        string pid = find(a, graph), qid = find(b, graph);
        double ratio = val * graph[b].second / graph[a].second;
        for(auto& g : graph){
            if(find(g.first, graph) == pid){
                g.second.second *= ratio;
            }
        }
        graph[pid].first = qid;
    }

    string find(string a, unordered_map<string, pair<string, double>>& graph){
        if(graph[a].first != a){
            graph[a].first = find(graph[a].first, graph);
        }
        return graph[a].first;
    }
};
