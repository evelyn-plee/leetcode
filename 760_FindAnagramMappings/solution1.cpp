// Time complexity: O(n), Space complexity: O(n)

class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        int n = A.size();
        map<int, int> indices;
        vector<int> ans;
        for(int i = 0; i < n; ++i){
            indices[B[i]] = i;
        }
        
        for(const int a : A){
            ans.push_back(indices[a]);
        }
        return ans;
    }
};
