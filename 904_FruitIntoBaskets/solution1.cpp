#include <vector>
#include <math>

using namespace std;

class Solution{
public:
    int totalFruit(vector<int>& tree){
        vector<pair<int, int>>  maxCnt;

        int cnt = 0, prev = -1;
        for(int i = 0; i < tree.size(); ++i){
            if(tree[i]==prev){
                ++cnt;
            } else{
                if(prev != -1) maxCnt.push_back({prev, cnt});
                cnt = 1; 
                prev = tree[i];
            }
        }
        maxCnt.push_back({prev, cnt});
        int res = INT_MIN, first = -1, second= -1, curCnt = 0;
        for(int i = 0; i < maxCnt.size(); i++){
            if(first == -1){
                first = maxCnt[i].first;
                curCnt += maxCnt[i].second;
            } else if(second == -1){
                second = maxCnt[i].first;
                curCnt += maxCnt[i].second;
            } else if(maxCnt[i].first == first || maxCnt[i].first == second){
                curCnt += maxCnt[i].second;
            }
             else{
                res = max(res, curCnt);
                first = maxCnt[i-1].first;
                second = maxCnt[i].first;
                curCnt = maxCnt[i-1].second + maxCnt[i].second;
            }
        }
        return max(res, curCnt);
    }    
};
