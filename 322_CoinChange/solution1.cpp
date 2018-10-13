#include <vector>
#include <math>
using namespace std;
class Solution{
public:
    int coinChange(vector<int>& coins, int amount){
        sort(coins.rbegin(), coins.rend());
        int ans = INT_MAX;
        coinChange(coins, 0, amount, 0, ans);
    }

private:
    void coinChange(const vector<int>& coins,
                    int i, int amount, int count, int& ans){
        if(amount == 0){
            ans = min(ans, count);
            return;
        }
        if(i == coins.size()) return;
        const int coin = coins[i];
        for(int k = amount / coin; k >= 0 && count + k < ans; k--){
            coinChange(coins, i+1, amount - k * coin, count + k, ans);
        }
    }
};
