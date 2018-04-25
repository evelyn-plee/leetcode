class Solution {
public:
    string countAndSay(int n) {
        if(n<1) return "";
        string ret = "1";
        for(int i=2; i<=n; i++) {
            string temp = "";
            int count = 1;
            char prev = ret[0];
            for(int j=1; j<ret.size(); j++) {
                if(ret[j]==prev)
                    count++;
                else {
                    temp += to_string(count);
                    temp.push_back(prev);
                    count = 1;
                    prev = ret[j];
                }
            }
            temp += to_string(count);
            temp.push_back(prev);
            ret = temp;
        }
        return ret;
    }
};
