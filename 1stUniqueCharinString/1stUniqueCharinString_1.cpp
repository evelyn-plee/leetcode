class Solution{
public:
  int firstUniqChar(string s) {
        int cnt[26] = {0};
        for (auto c : s){
            cnt[c - 97]++;
        }
        for (auto i = 0; i<s.length(); i++){
            if (cnt[s[i] - 97] == 1){
                return i;
            }
        }
        return -1;
    }
};
