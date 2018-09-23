#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int> hand, int W){
        if(hand.size() % W != 0) return false;
        sort(hand.begin(), hand.end());
        while(!hand.empty()){
            int cur = hand[0];
            hand.erase(hand.begin());
            for(int i = 1; i < W; i++){
                cur += 1;
                auto it = find(hand.begin(), hand.end(), cur);
                if(it == hand.end()) return false;
                else hand.erase(it);
            }
        }
        return true;
    }
};
