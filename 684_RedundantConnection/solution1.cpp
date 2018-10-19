/**
* Use disjoint set union with path compression
*/

class UnionFindSet(){
public:
    UnionFindSet(int n){
        parents_ = vector<int>(n+1, 0);
        ranks_ = vector<int>(n+1, 0);
    }
    
    bool Union(int u, int v){
        int pu = Find(u);
        int pv = Find(v);
        if(pu == pv) return false;
        if(ranks_[pv] > ranks_[pu]) parents_[pv] = pu;
        else if(ranks_[pu] > ranks_[pv]) parents_[pu] = pv;
        else{
            parents_[pv] = pu;
            ranks_[pv] += 1;
        }
        return true;
    }
    
    int Find(int u){
        if(u != parents_[u]){
            parents_[u] = Find(parents_[u]);
        }
        return parents_[u];
    }
private:
    vector<int> parents_;
    vector<int> ranks_;
};

class Solution{
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges){
        UnionFindSet s(edges.size());
        for(const auto& edge: edges){
            if(!s.Union(edge[0], edge[1])) return edge;
        }
        return {};
    }
};
