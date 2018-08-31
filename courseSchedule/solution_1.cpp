class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if(prerequisites.empty())
            return true;
        vector<int> inDegree(numCourses);
        for(auto x : prerequisites){
            inDegree[x.first]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
			if (inDegree[i] == 0)
				q.push(i);
		}
        int count = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            count++;
            for(auto x : prerequisites){
                if(x.second == u){
                    inDegree[x.first]--;
                    if(inDegree[x.first]==0)
                        q.push(x.first);
                }
            }
        }
        return count < numCourses ? false : true;
    }
};
