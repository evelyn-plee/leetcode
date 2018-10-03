#include <vector>
#include <math>

using namespace std;

class Solution{
public:
    int kEmptySlots(vector<int>& flowers, int k){
        int n = flowers.size();
        if(n == 0 || k >= n) return -1;
        
        vector<int> day(n, 0);
        for(int i = 0; i < n; ++i){
            day[flowers[i]-1] = i+1;
        }
        
        int itr = 0, res = INT_MAX;
        while(itr < n - k - 1){
            int tmp = max(day[itr], day[itr+k+1]);
            int end = itr + k + 1;
            for(int i = itr; i < end; i++){
                if(day[i] < tmp){
                    itr = i;
                    break;
                }
            }
            if(itr + k + 1 == end){
                res = min(res, tmp);
                itr++;
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
