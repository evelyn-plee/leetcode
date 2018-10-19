class LRUCache{
public:
    LRUCache(int capacity){
        capacity_ = capacity;
    }
    
    int get(int key){
        const auto it = m_.find(key);
        if(it == m.end()) return -1;
        cache_.splice(cache_.begin(), cache_, it->second);
        return it->second->second;
    }
    
    void put(int key, int value){
        const auto it = m_.find(key);
        if(it != m.end()){
            it->second->second = value;
            cache_.splice(cache_.begin(), cache_, it->second);
            return;
        }
        if(cache_.size() == capacity_){
            const auto& lru = cache_.back();
            m_.erase(lru.first);
            lru.pop_back();
        }
        cache_.emplace_front(key, value);
        m_[key] = cache_.begin();
    }

private:
    int capacity_;
    unordered_map<int, list<pair<int, int>>::iterator> m_;
    list<pair<int, int>> cache_;
};
