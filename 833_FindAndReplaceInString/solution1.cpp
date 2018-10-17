// Time complexity: O(NQ) - N length of S, and Q replacement of targets
// Space complexity: O(n)

class Solution {
public:
   string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        int n = indexes.size();
        vector<pair<int, int>> mp;

        for(int i = 0; i < n; ++i){
            mp.push_back(make_pair(indexes[i], i));
        }

        sort(mp.rbegin(), mp.rend());

        for(int i = 0; i < n; ++i){
            int first = mp[i].first;
            int second = mp[i].second;
            if(S.find(sources[second], first) == first){
                S.replace(first, sources[second].length(), targets[second]);
            }
        }
        return S;
    }
};
