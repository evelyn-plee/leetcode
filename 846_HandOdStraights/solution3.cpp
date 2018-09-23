#include<vector>

using namespace std;

class Solution{
public:
    bool isNStraightHand(vector<int> hand, int W){
        if(W == 1) return true;
        if(hand.size() % W != 0) return false;
        
        vector<int> group(W,0);
        for(auto c : hand) ++group[c % W];
        
        int expected = group[0];
        for(auto c : group){
            if(c != expected) return false;
        }
        return true;
    }
};
