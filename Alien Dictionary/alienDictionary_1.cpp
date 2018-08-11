class Solution {
public:
    string alienOrder(vector<string>& words) {
        if(words.size() == 0) return "";
        unordered_map<char, int> indegree;
        unordered_map<char, unordered_set<char>> graph;
        
        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words[i].size(); j++){
                char c = words[i][j];
                indegree[c] = 0;
            }
        }
        
        for(int i = 0; i < words.size() - 1; i++){
            string cur = words[i];
            string next = words[i+1];
            int len = min(cur.size(), next.size());
            for(int j = 0; j < len; j++){
                if(cur[j] != next[j]){
                    unordered_set<char> set = graph[cur[j]];
                    if(set.find(next[j]) == set.end()){
                        graph[cur[j]].insert(next[j]);
                        indegree[next[j]]++;
                    }
                    break;
                }
            }
        }
        
        // topological sort
        string ret; queue<char> q;
        for(auto& e : indegree){
            if(e.second == 0) q.push(e.first);
        }
        while(!q.empty()){
            char cur = q.front(); q.pop();
            ret += cur;
            if(graph[cur].size() != 0){
                for(auto& e : graph[cur]){
                    indegree[e]--;
                    if(indegree[e] == 0){
                        q.push(e);
                    }
                }
            }
        }
        // check if it is cylic
        return ret.length() == indegree.size() ? ret : "";
    }
};
