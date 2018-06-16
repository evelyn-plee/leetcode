class Solution{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs){
        vector<vector<string>> res;
        map<string, vector<string>> mp;

        for(int i = 0; i < strs.size(); i++){
            string key = strs[i];
            sort(key.begin(), key.end());
            if(mp.find(key) == mp.end()){
                mp[key] = vector<string>(1, strs[i]);
            } else {
                mp[key].push_back(strs[i]);
            }
        }

        for(auto it = mp.begin(); it != mp.end(); i++){
            res.push_back(it->second);
        }
        return res;
    }
};
