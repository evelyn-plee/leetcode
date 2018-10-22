//O(n), O(n)

class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLength = 0, end = -1;
        stack<int> st;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '(') st.push(i);
            else if(st.empty()) end = i;
            else{
                st.pop();
                int start = st.empty() ? end : st.top();
                maxLength = max(maxLength, i-start);
            }
        }
        return maxLength;
    }
};
