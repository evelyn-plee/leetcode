class WordDictionary{
public:
    /** Initialize your data structure here. */
    WordDictionary() : root(new TrieNode()){}
    
    ~WordDictionary() {delete root;}
    
    /** Adds a word into the data strcuture */
    void addWord(string word){
        addWord(word, 0, root);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word){
        return search(word, 0, root);
    }
    
private:
    struct TrieNode{
        TrieNode(): child(vector<TrieNode*>(26, NULL)), isLeaf(false){}
        ~TrieNode() {for(TrieNode* node : child) delete node;}
        vector<TrieNode*> child;
        bool isLeaf;
    }
    
    TrieNode* root;
    
    void addWord(const string& word, int i, TrieNode* cur){
        if(i == word.length()) return;
        int j = word[i] - 'a';
        if(!cur->child[j]){
            cur->child[j] = new TrieNode();
        }
        if(i == word.length()-1){
            cur->child[j]->isLeaf = true;
        }
        addWord(word, i+1, cur->child[j]);
    }
    
    bool search(const string& word, int i, TrieNode* cur){
        if(i == word.length()) return false;
        if(word[i] != '.'){
            int j = word[i] - 'a';
            if(!cur->child[j]) return false;
            if(i == word.length() - 1 && cur->child[j]->isLeaf) return true;
            return search(word, i+1, cur->child[j]);
        } else{
            for(TrieNode* node : cur->child){
                if(node){
                    if(i == word.length() - 1 && node->isLeaf) return true;
                    if(search(word, i+1, node)) return true;
                }
            }
            return false;
        }
    }
};
