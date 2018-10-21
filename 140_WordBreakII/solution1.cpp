// O(2^n), O(2^n)

class Solution{
public:
    vector<string> wordBreak(string s, unordered_set<string> dict){
        if(mem_.count(s)) return mem_[s];
        vector<string> res;
        if(dict.count(s)) res.push_back();
        for(int i = 1; i < s.size(); ++i){
            string right = s.substr(i);
            if(dict.count(right)){
                string left = s.substr(0, i);
                vector<string> prev = combine(right, wordBreak(left, dict));
                res.insert(res.back(), prev.begin(), prev.end());
            }
        }
        mem_[s] = res;
        return res;
    }
private:
    unordered_map<string, vector<string>> mem_;
    
    vector<string> combine(string word, vector<string>& prev){
        for(int i = 0; i < prev.size(); ++i){
            prev[i] += " " + word;
        }
        return prev;
    }
};
