// Greedy, Time complexity: O(n + rows), Space Complexity: O(n)

class Solution{
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols){
        string fullSentence;
        for(string word : sentence) fullSentence += (word + " ");
        int start = 0, len = fullSentence.length();
        for(int i = 0; i < rows; ++i){
            start += cols;
            if(fullSentence[start % len] == ' '){
                ++start;
            }else{
                while(start > 0 && fullStence[(start-1) % len] != ' '){
                    --start;
                }
            }
        }
        return start / len;
    }
};
