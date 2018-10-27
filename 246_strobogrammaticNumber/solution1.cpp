class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> dict{{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9','6'}};
        int n = num.length();
        for(int l = 0, r = n-1; l <= r; l++, r--){
            if(dict.find(num[l]) == dict.end() || dict[num[l]] != num[r]) return false;
        }
        return true;
    }
};
