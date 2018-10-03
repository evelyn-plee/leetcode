#include<vector>

using namespace std;

class Trie {
public:
    /** Initialize your data structure here. */
    Trie(): root_(new TrieNode()) {}
    
    /** Inserts a word into the trie. */
    void insert(const string& word) {
        TrieNode* p = root_.get();
        for (const char c : word) {
            if (!p->children[c - 'a'])
                p->children[c - 'a'] = new TrieNode();
            p = p->children[c - 'a'];
        }
        p->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(const string& word) const {
        const TrieNode* p = find(word);
        return p && p->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(const string& prefix) const {
        return find(prefix) != nullptr;
    }
private:
    struct TrieNode {
        TrieNode():is_word(false), children(26, nullptr){}
        
        ~TrieNode() {
            for (TrieNode* child : children)
                if (child) delete child;
        }
               
        bool is_word;
        vector<TrieNode*> children;
    };
    
    const TrieNode* find(const string& prefix) const {
        const TrieNode* p = root_.get();
        for (const char c : prefix) {
            p = p->children[c - 'a'];
            if (p == nullptr) break;
        }
        return p;
    }
    
    std::unique_ptr<TrieNode> root_;
};
/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
