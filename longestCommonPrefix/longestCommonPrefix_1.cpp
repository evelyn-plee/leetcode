class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        bool done=false;
        int pos=-1;
        while(!done)
        {
            if(++pos==strs[0].size()) break;
            char c=strs[0][pos];
            for(int i=1; i<strs.size();i++)
            {
                if(strs[i].size()<=pos || strs[i][pos] != c)
                {
                    done=true;
                    break;
                }
            }
        }
        return pos==0?"":strs[0].substr(0,pos);
    }
};
