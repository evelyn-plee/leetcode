class Solution{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs){
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;

        for(string str : strs){
            vector<int> cnt(26,0);
            string t = "";
            for(char c : str) ++cnt[c - 'a'];
            for(int d : cnt) t += to_string(d) + "/";
            mp[t].push_back(str);
        }

        for(auto a : mp){
            res.push_bacK(a.second);
        }
        return res;
    }
};
