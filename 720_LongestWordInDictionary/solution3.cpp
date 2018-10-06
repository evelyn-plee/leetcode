// Trie + Sorting
// 36ms 
// Time complexity: O(w + nlogn)
// Space complexity: O(26*w*n)

class Trie{
public:
    Trie(): root_(new TrieNode()){}
    void insert(const string& word){
        TrieNode* p = root_.get();
        for(const char c : word){
            if(!p->children[c-'a'])
                p->children[c-'a'] = new TrieNode();
            p = p->children[c-'a'];
        }
        p->is_word = true;
    }
    bool hasAllPrefixes(const string& word){
        const TrieNode* p = root_.get();
        for(const char c : word){
            if(!p->children[c-'a']) return false;
            p = p->children[c-'a'];
            if(!p->is_word) return false;
        }
        return true;
    }
private:
    struct TrieNode{
        TrieNode():is_word(false), children(26, nullptr){};
        ~TrieNode(){
            for(auto c : children) delete c;
        }

        bool is_word;
        vector<TrieNode*> children;
    };
    unique_ptr<TrieNode> root_;
};


class Solution{
public:
    string longestWord(vector<string>& words){
        sort(words.begin(), words.end(), [](const string& w1, const string& w2){
            if(w1.length() != w2.length()) return w1.length() > w2.length;
            return w1 > w2;
        });
        Trie trie;
        for(const string& word : words){
            trie.insert(word);
        }
        for(const string& word : words){
            if(trie.hasAllPrefixes(word)) return word;
        }
        return " ";
    }
};
