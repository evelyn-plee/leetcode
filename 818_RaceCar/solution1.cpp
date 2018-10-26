// Using BFS

class Solution {
public:
    int racecar(int target) {
        queue<pair<int, int>> que;
        que.push({0, 1});
        unordered_set<int> visit;
        visit.insert(0*10000 + 1);
        int level = 0;
        while(!que.empty()){
            int size = que.size();
            for(int i = 0; i < size; ++i){
                pair<int, int> top = que.front();
                que.pop();
                int pos = top.first, speed = top.second;
                if(pos == target) return level;
                int tmp1 = (pos+speed)*10000 + 2*speed;
                int speed2 = speed > 0 ? -1: 1;
                int tmp2 = pos*10000 + speed2;
                if(abs(pos + speed - target) < target && visit.find(tmp1) == visit.end()){
                    visit.insert(tmp1);
                    que.push({pos+speed, 2*speed});
                }
                
                if(abs(pos - target) < target && visit.find(tmp2) == visit.end()){
                    visit.insert(tmp2);
                    que.push({pos, speed2});
                }
            }
            level++;
        }
    }
};
