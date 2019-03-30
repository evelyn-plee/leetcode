class UF{
public:
    UF(int n) : parent(n){}
    
    void setParent(int x, int p){
        parent[x] = p;
    }
    
    int find(int x){
        if(x != parent[x]) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    bool union_find(int x, int y){
        int px = find(x);
        int py = find(y);
        if(px == py) return false;
        
        parent[px] = py;
        return true;
    }
private:
    vector<int> parent;
};

class Solution{
public:
    int minSwapsCouples(vector<int> &row){
        if(row.empty()) return 0;
        int N = row.size();
        UF uf(N);
        
        for(int i = 0; i < N; i += 2){
            uf.setParent(row[i], row[i]);
            uf.setParent(row[i+1], row[i]);
        }
        
        int counter = 0;
        for(int i = 0; i < n; i += 2){
            // if need to merge, means swap is needed
            if(uf.union_find(i, i+1)) counter++;
        }
        
        return counter;
    }
}
