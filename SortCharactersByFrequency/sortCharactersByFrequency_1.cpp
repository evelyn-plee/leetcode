class Solution{
public: 
    string frequencySort(string s){
        string ans;
        
        unordered_map<char, int> freqMap;
        map<int, vector<char>> ansMap;
        
        for(auto c:s){
            freqMap[c]++;
        }
        
        for(auto f:freqMap){
            ansMap[f.second].push_back(f.first);
        }
        
        for(auto it = ansMap.rbegin(); it != ansMap.rend(); ++it){
            for(auto c : it->second){
                ans.append(it->first, c);
            }
        }
        return ans;
    }
};
