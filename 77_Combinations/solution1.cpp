class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> chosen;
        vector<vector<int>> combs;
        
        if(k == 0 || n == 0 || n<k) return combs;
        generateCombinations(n, k, 1, chosen, combs);
        return combs;        
    }
private:
    void generateCombinations(int n, int k, int idx, vector<int>& chosen, 
    vector<vector<int>>& combs) {
        if (chosen.size() == k) {
            combs.push_back(chosen);
            return;
        }
        for (int i = idx; i <= n; ++i) {
            chosen.push_back(i);
            generateCombinations(n, k, i + 1, chosen, combs);
            chosen.pop_back();
        }
    }
};
