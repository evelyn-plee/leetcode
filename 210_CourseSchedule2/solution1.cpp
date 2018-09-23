#include<string>
#include<queue>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites){
        if(prerequisites.empty()) return;
        vector<int> res;
        vector<vector<int>> graph(numCourses, vector<int>(0));
        vector<int> inDegree(numCourses, 0);

        for(auto a : prerequisites){
            ++inDegree[a.first];
            graph[a.second].emplace_back(a.first);
        }

        queue<int> q;
        for(int i = 0; i < numCourses; ++i){
            if(inDegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int tmp = q.front(); q.pop();
            res.emplace_back(tmp);
            for(auto a : graph[tmp]){
                --inDegree[a];
                if(inDegree[a] == 0) q.push(a);
            }
        }
        
        if(res.size() != numCourses) res.clear();
        return res;

    }
};
