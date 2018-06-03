#include <vector>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int maxProfit = 0, mn = INT_MAX;
        for(int i = 0; i<prices.size(); i++){
            mn = prices[i] < mn ? prices[i] : mn;
            maxProfit = prices[i] - mn > maxProfit ? prices[i] - mn : maxProfit;
        }
        return maxProfit;
    }
};