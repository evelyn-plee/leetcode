/**
* Hash map - brute force + sorting
* Time complexity - O(W^2 + nlogn)
* Space complexity - O(n + W)
* 28 ms
*/

#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution{
public:
    string longestWord(vector<string>& words){
        sort(words.begin(), words.end(), [](const string& w1, const string& w2){
            // sort by descending order
            if(w1.length() != w2.length()) return w1.length() > w2.length();
            // if same length sort by lexical order
            return w1 < w2;
        });
        //for(int i = 0; i < words.size(); ++i){
        //    cout << words[i] << endl;
        //}
        unordered_set<string> dict(words.begin(), words.end());
        for(const string& word : words){
            string prefix; bool valid = true;
            for(int i = 0; i < word.length()-1 && valid; ++i){
                prefix += word[i];
                if(!dict.count(prefix)) valid = false;}
            if(valid) return word;
        }
        return " ";
    }
};
