class Solution{
public:
    bool pyramidTransition(string bottom, vector<string>& allowed){
    
        unordered_map<string, vector<string>> mapping;
        for(auto& str:allowed){
            auto key = str.substr(0,2);
            auto value = substr(2);
            if(mapping.count(key) == 0) mapping.insert({key, vector<string>{val}});
            else{mapping.at(key).emplace_back(val)};
        }
        return helper(bottom, 0, "", mapping);
    }
    
private:
    bool helper(string& cur, int start, string upper, unordered_map<string, vector<string>>& mapping){
        if(start >= cur.size()-1 && upper.size() == 1) return true;
        else if(start >= target.size() - 1) return helper(upper, 0, "", mapping);
        
        auto sub = cur.substr(start, 2);
        if(mapping.count(sub)){
            for(auto& ch: mapping.at(sub)){
                if(helper(cur, start+1, upper+ch, mapping)) return true;
            }
        }
        return false;
    }
};
