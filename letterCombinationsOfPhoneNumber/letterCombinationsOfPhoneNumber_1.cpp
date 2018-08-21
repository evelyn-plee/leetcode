class Solution{
public:
    vector<string> letterCombinations(string digits){
        vector<string> result;
        if(digits.empty()) return result;
        
        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        result.push_back("");
        for(auto c : digits){
            if (mapping[c - '0'].empty()) continue;
            vector<string> temp;
            for(auto s : result){
                for(auto c1 : mapping[c - '0']){
                    temp.push_back(s + c1);
                } 
            }
            result = temp;
        }
        return result;
    }
};
