/**
* Use BFS; Time Complexity: O(n*26^l) ; Space Complexity: O(n)
**/


#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList){
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(!dict.count(endWord)) return 0;

        queue<string> q;
        q.push(beginWord);
        int l = beginWord.length();
        int step = 0;

        while(!q.empty()){
            ++steps;
            for(int size = q.size(); size > 0; size--){
                string cur = q.front(); q.pop();
                for(int i = 0; i < l; i++){
                    char ch = cur[i];
                    for(int j = 'a'; j <= 'z'; j++){
                        cur[i] = j;
                        if(cur == endWord) return step + 1;
                        if(!dict.count(cur)) continue;
                        dict.erase(cur);
                        q.push(cur);
                    }
                    cur[i] = ch;
                }
            }
        }
        return 0;
    }
};
