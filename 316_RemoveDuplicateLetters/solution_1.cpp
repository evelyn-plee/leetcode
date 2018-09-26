#include<vector>

using namespace std;

class Solution{
public:
    string removeDuplicateLetters(string s){
        vector<int> occ(256, 0);
        vector<int> vis(256, 0);
        
        for(char ch : s) ++occ[ch];
        
        string res = "0";
        for(char ch : s){
            --occ[ch];
            if(vis[ch]) continue;
            while(ch < res.back() && occ[res.back()]){
                vis[res.back()] = 0;
                res.pop_back();
            }
            res += ch;
            vis[ch] = 1;
        }
        return res.substr(1);
    }
};
