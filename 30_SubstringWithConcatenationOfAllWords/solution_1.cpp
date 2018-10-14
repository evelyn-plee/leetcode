class Solution{
public:
    vector<int> findSubstring(string s, vector<string>& words){
        vector<int> res;
        if(s.empty() || words.empty()) return res;
        int n = words.size(), m = words[0].size();
        unordered_map<string, int> m1;
        for(auto &a: words) ++m1[a];
        for(int i = 0; i <=(int)s.size() - n*m ; ++i){
            unordered_map<string, int> m2;
            int j = 0;
            for(int j = 0; j < n; ++j){
                string cur = s.substr(i+j*m, m);
                if(m1.find(cur) == m1.end()) break;
                ++m2[cur];
                if(m2[cur] > m1[cur]) break;
            }
            if(j == n) res.push_back(i);
        }
        return res;
    }
};
