// Using hashtable and treemap
// Time Complexity: 
// Set -> O(log n) for single operation
// Get -> O(log n) for single operation
// Space Complexity: O(n)

class TimeMap{
public:
    /** Initialize your data structure here.
    TimeMap(){}
    
    void set(string key, string value, int timestamp){
        s_[key].emplace(timestamp, value);
    }
    
    string get(string key, int timestamp){
        auto m = s_.find(key);
        if(m == s_.end()) return "";
        auto it = m->second.upper_bound(timestamp);
        return it == begin(m->second) ? "" : prev(it)->second;
    }
private:
    unordered_map<string, map<int, strin>> s_;
}
