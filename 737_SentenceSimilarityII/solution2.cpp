/** Union-find set Time complexity: O(|pairs| + |words|), Space complexity: O(|pairs|) **/

class UnionFindSet{
public:
    UnionFindSet(int n){
        parents_ = vector<int>(n+1, 0);
        ranks_ = vector<int>(n+1, 0);
        for(int i = 0; i < parents_.size(); ++i){
            parents_[i] = i;
        }
    }
    
    bool Union(int u, int v){
        int pu = Find(u);
        int pv = Find(v);
        if(pu == pv) return false;
        if(ranks_[pu] > ranks_[pv]) parents_[pv] = pu;
        else if(ranks_[pv] > ranks_[pu]) parents_[pu] = pv;
        else{
            parents_[pu] = pv;
            ++ranks_[pv];
        }
        return true;
    }
    
    int Find(int id){
        if(id != parents_[id]) parents_[id] = Find(parents_[id])
        return parents_[id];
    }
    
private:
    vector<int> parents_;
    vector<int> ranks_;
};

class Solution{
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>>& pairs) {
        if (words1.size() != words2.size()) return false;
        UnionFindSet s(pairs.size * 2);
        unordered_map<string, int> word2Ind;
        
        for(const auto& p : pairs){
            int u = getIndex(p.first, word2Ind, true);
            int v = getIndex(p.second, word2Ind, true);
            s.Union(u, v);
        }
        
        for(int i = 0; i < words1.size(); ++i){
            if(words1[i] == words2[i]) continue;
            int u = getIndex(words1[i], word2Ind);
            int v = getIndex(words2[i], word2Ind);
            if(u < 0 || v < 0) return false;
            if(s.Find(u) != s.Find(v)) return false;
        }
        return true;
    }
private:
    int getIndex(const string& word, unordered_map<string, int>& word2Ind, bool create = false){
        auto it = word2Ind.find(word);
        if(it == word2Ind.end()){
            if(!create) return INT_MIN;
            int index = word2Ind.size();
            wordInd.emplace(word, index);
            return index;
        }
        return it->second;
    }
}
