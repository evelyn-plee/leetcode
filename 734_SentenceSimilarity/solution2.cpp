class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        
        if(words1.size() != words2.size()) return false;
        
        for(int i = 0; i < words1.size(); ++i){
            if(words1[i] == words2[i]) continue;
            pair<string, string> p1 = {words1[i], words2[i]};
            pair<string, string> p2 = {words2[i], words1[i]};
            if(find(pairs.begin(), pairs.end(), p1) != pairs.end() || find(pairs.begin(), pairs.end(), p2) != pairs.end()) continue;   
            return false;
        }
        return true;
    }
};
