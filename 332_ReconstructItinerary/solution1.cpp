// Time Complexity: O(N log D)
// Space Complexity: O(N)

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        route_.clear();
        trips_.clear();
        
        for(const auto& pair : tickets)
            trips_[pair.first].push_back(pair.second);
        
        
        // Greedily sort the value 
        for(auto& pair : trips_) {
            auto& dests = pair.second;
            std::sort(dests.begin(), dests.end());
        }
        
        const string kStart = "JFK";
        
        visit(kStart);
        
        return vector<string>(route_.crbegin(), route_.crend());
    }
private:

    unordered_map<string, deque<string>> trips_;    

    vector<string> route_;
    
    // Perform Post-Order Traversal, to prevent dead end
    void visit(const string& src) {
        auto& dests = trips_[src];
        while (!dests.empty()) {
            const string dest = dests.front();
            // Remove the ticket to prevent revisitng
            dests.pop_front();
            visit(dest);
        }
        // Add current node to the route
        route_.push_back(src);
    }
};
