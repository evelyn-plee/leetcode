class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() { }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        wordMap[word.length()].push_back(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        int n = word.length();
        auto it = wordMap.find(n);
        if(it == wordMap.end()) return false;
        for(auto a : wordMap[n]){
            int i = 0;
            for(; i < n; ++i){
                if(word[i] == '.') continue;
                else{
                    if(word[i] != a[i]) break;
                }
            }
            if(i == word.size()) return true;
        }
        return false;
    }
private:
    unordered_map<int, vector<string>> wordMap;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
