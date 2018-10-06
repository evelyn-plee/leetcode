#include <string>
#include <unordered_map>

using namespace std;

class Solution{
public:
    string getHint(string secret, string guess){
        unordered_map<char, int> counts;
        int bullCount = 0, cowCount = 0;
        for(int i = 0; i < secret.size(); ++i){
            if(secret[i] == guess[i]){
                ++bullCount;
                guess[i] = 0;
            }
            else ++counts[secret[i]];
        }

        for(char c : guess){
            if(c && counts[c]){
                ++cowCount;
                --counts[c];
            }
        }
        return to_string(bullCount) + "A" + to_string(cowCount) + "B";
    }
};
