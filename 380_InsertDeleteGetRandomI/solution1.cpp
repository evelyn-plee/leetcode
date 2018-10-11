class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {}
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m_.count(val)) return false;
        m_[val] = vals_.size();
        vals_.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(!m_.count(val)) return false;
        int index = m_[val];
        m_[vals_.back()] = index;
        m_.erase(val);
        std::swap(vals_[index], vals_.back());
        vals_.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int index = rand() % vals_.size();
        return vals_[index];
    }
private:
    // val -> index in the array
    unordered_map<int, int> m_;
    vector<int> vals_;
};
