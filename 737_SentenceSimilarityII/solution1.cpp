/** Time complexity: O(|Pairs| * |words1|), Space Complexity: O(|Pairs|) **/

class Solution{
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2,
                                vector<pair<string, string>>& pairs){
                                
        if(words1.size() != words2.size()) return false;
        
        graph.clear();
        
        for(const auto& p : pairs){
            graph[p.first].insert(p.second);
            graph[p.second].insert(p.first);
        }
        unordered_set<string> visited;
        for(int i = 0; i < words1.size(); ++i){
            visited.clear();
            if(!dfs(words1[i], words2[i], visited)) return false;
        }
        return true;
    }
private:
    unordered_map<string, unordered_set<string>> graph;
    bool dfs(const string& src, const string& dst, unordered_set<string>& visited){
        if(src == dst) return true;
        visited.insert(src);
        for(const auto& next : graph[src]){
            if(visited.count(next)) continue;
            if(dfs(next, dst, visited)) return true;
        }
        return false;
    }
};
