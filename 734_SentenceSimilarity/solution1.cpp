// Time complexity: O(|pairs| + |words|), Space complexity: O(|pairs|)

class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        
        if(words1.size() != words2.size()) return false;
        
        unordered_map<string, unordered_set<string>> similar_words;
        for(const auto& p : pairs){
            similar_words[p.first].insert(p.second);
            similar_words[p.second].insert(p.first);
        }
        for(int i = 0; i < words1.size(); ++i){
            if(words1[i] == words2[i]) continue;
            if(!similar_words[words1[i]].count(words2[i])) return false;
        }
        return true;
    }
};
