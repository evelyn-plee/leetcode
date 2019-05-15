#include <vector>

using namespace std;

// Modify input
class DFS1_Solution{
public:
    int findCircleNum(vector<vector<int>>& M){
        if(M.empty()) return 0;
        int n = M.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(!M[i][i]) continue;
            ans++;
            dfs(M, i, n);
        }
        return ans;
    }

private:
    void dfs(vector<vector<int>>& M, int cur, int n){
        for(int i = 0; i < n; i++){
            if(!M[cur][i]) continue;
            M[cur][i] = M[i][cur] = 0;
            dfs(M, i, n);
        }
    }
};

// Without modifying input
class DFS2_Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if(M.empty()) return 0;
        int n = M.size();
        vector<int> visited(n, 0);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(visited[i]) continue;
            dfs(M, visited, i);
            ans++;
        }
        return ans;
    }
    
private:
    void dfs(vector<vector<int>>& M, vector<int>& visited, int cur){
        if(visited[cur]) return;
        visited[cur] = 1;
        for(int i = 0; i < M[cur].size(); i++){
            if(M[cur][i] == 1 && !visited[i]) dfs(M, visited, i);
        }
    }
};


class BFS_Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if(M.empty()) return 0;
        int n = M.size();
        int count = 0;
        vector<int> visited(n, 0);
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                q.push(i);
                while(!q.empty()){
                    int cur = q.front(); q.pop(); cout << i << endl;
                    visited[cur] = 1;
                    for(int j = 0; j < n; j++){
                        if(M[cur][j] && !visited[j]) q.push(j);
                    }   
                }
                count++;
            }
        }
        return count;
    }
};
