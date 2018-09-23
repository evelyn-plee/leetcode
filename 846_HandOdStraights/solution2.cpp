#include<string>
#include<vector>
#include<priority_queue>
#include<map>

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int> hand, int W){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        unordered_map<int, int> map;

        if(hand.size() % W) return false;

        for(int i = 0; i < hand.size(); i++) ++map[hand[i]];

        for(auto it = map.begin(); it != map.end(); it++){
            q.push({it->first, it->second});
        }

        while(!q.empty()){
            int count = W;
            pair<int, int> card;
            vector<pair<int, int>> tmp;
            int prev = q.top().first - 1;
            while(count){
                card = q.top();
                if(card.first != prev + 1) return false;
                q.pop();
                card.second--;
                if(card.second > 0) tmp.push_back(card);
                ++prev;
                --count;
            }

            for(auto c : tmp) q.push(c);
        }
        return true;
    }
};
