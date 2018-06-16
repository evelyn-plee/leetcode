class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        int PRIMES[] = {2, 3, 5, 7, 11 ,13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 107};
        unordered_map<int, vector<string>> mp;
        for (const auto& s: strs) {
            int k = 1;
            for (const auto c: s) {
                k *= PRIMES[c-'a'];
            }
            mp[k].push_back(s);
        }
        for ( auto it = mp.begin(); it != mp.end(); ++it ) {
            result.push_back(it->second);
        }
        return result;
    }
};
