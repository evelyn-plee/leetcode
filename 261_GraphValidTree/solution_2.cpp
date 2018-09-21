#include <vector>
#include <iostream>

using namespace std;

class Solution{
public:
    bool validTree(int n, vector<pair<int, int>>& edges){
        vector<int> root(n, -1);
        
        int cnt = n;
        for(int i = 0; i < n; i++) root[i] = i;
        for(auto& e : edges){
             int p = find(root, e->first);
             int q = find(root, e->second);
             if(p == q) return false;
             root[p] = q;
             cnt--;
        }
        return cnt == 1;
    }
    
    int find(vector<int>& root, int p){
        while(root[p]!= p){
            root[p] = root[root[p]];
            p = root[p];
        }
        return p;
    }
};
