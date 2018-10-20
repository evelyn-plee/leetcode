// Use backtracking

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        bool visit[10] = {false};
        int count = 0;
        for(int i = 0; i <= min(10, n); ++i){
            count += dfs(i, 0, visit);
        }
        return count;
    }
private:
    int dfs(int target, int idx, bool* visit){
        if(target == idx) return 1;
        int count = 0;
        for(int i = idx ? 0 : 1; i < 10; i++){
            if(!visit[i]){
                visit[i] = true;
                count += dfs(target, idx+1, visit);
                visit[i] = false;
            }
        }
        return count;
    }
};
