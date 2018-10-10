/**
Difference between this solution with solution1 is we're not changing M values.
Time complexity: O(n^2). The complete matrix of size n^2 is traversed.
Space complexity: O(n). visited array of size n is used.
*/


#include <vector>

using namespace std;

class Solution{
public:
    int findCircleNum(const vector<vector<int>>& M){
        if(M.empty()) return 0;
        int n = M.size(); int ans = 0;
        vector<int> visited(n, 0);
        for(int i = 0; i < n; ++i){
            if(visited[i]) continue;
            dfs(M, i, visited);
            ++ans;
        }
        return ans;
    }

private:
    void dfs(const vector<vector<int>>& M, int cur, vector<int>& visited){
        if(visited[cur]) return;
        visited[cur] = 1;        
        for(int i = 0; i < M.size(); ++i){
            if(!visited[i] && M[cur][i]) dfs(M, i, visited);
        }
    }
};
